#include<iostream>
#include"NetTopo.h"
using namespace std;
//const int DefaultVertices=200;  //默认的拓扑的最大顶点数
const int inf=1000;//最大权值
//构造函数
NetTopo::NetTopo(int sz)
{
    maxVertices=sz;//设置最大顶点数
    numVertices=0;//当前定点数设置为0
    numEdges=0;//当前边数设置为0
    VerticesList=new int[maxVertices];//建立顶点表数组

    Edge=(int **)new int*[maxVertices];//建立邻接矩阵
    for(int i=0;i<maxVertices;++i)
        Edge[i]=new int[maxVertices];
    //邻接矩阵初始化
    for(int i=0;i<maxVertices;++i)
        for(int j=0;j<maxVertices;++j)
    {
        Edge[i][j]=((i==j)? 0:inf);
    }
}

//顶点插入函数
bool NetTopo::insertVertex(int v)
{
    //判断是否还有空位置
    if(numVertices==maxVertices)
        return false;
    VerticesList[numVertices]=v;
    ++numVertices;
}

//给出顶点在顶点表中的下标
int NetTopo::getVertexPos(int v)
{
    for(int i=0;i<numVertices;++i)
    {
        if(VerticesList[i]==v)
            return i;
    }
    return -1;
}

//返回边(v1,v2)上的权值，若存在顶点不在图中，则函数返回0
int NetTopo::getWeight(int v1,int v2)
{
    if(v1!=-1&&v2!=-1)
        return Edge[v1][v2];
    return 0;
}

//带权边插入函数
bool NetTopo::insertEdge(int v1,int v2,int cost)
{
    if(v1>-1&&v1<maxVertices&&v2>-1&&v2<maxVertices&&Edge[v1][v2]==inf)
    {
        Edge[v1][v2]=Edge[v2][v1]=cost;
        numEdges++;
        return true;
    }
    else
        return false;
}
//删除边(v1,v2)
bool NetTopo::removeEdge(int v1,int v2)
{
    if(v1>-1&&v1<maxVertices&&v2>-1&&v2<maxVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<inf)
    {
        Edge[v1][v2]=Edge[v2][v1]=inf;
        numEdges--;
        return true;
    }
    else
        return false;
}
//删除节点v及相关的边
bool NetTopo::removeVertex(int v)
{
    if(v<0||v>numVertices)//顶点v不存在图中
        return false;
    if(numVertices==1)//当只剩一个顶点时，不进行删除
        return false;
    VerticesList[v]=VerticesList[numVertices-1];//首先从顶点表中删除该顶点

    //重新计算当前拓扑中的边数（减去少掉的边）
    for(int i=0;i<numVertices;++i)
    {
        if(Edge[i][v]>0&&Edge[i][v]<inf)
            numEdges--;
    }
    //使用最后一列填补第v列
    for(int i=0;i<numVertices;++i)
        Edge[i][v]=Edge[i][numVertices-1];
    numVertices--;
    //使用最后一行填补第v行
    for(int i=0;i<numVertices;++i)
        Edge[v][i]=Edge[numVertices][i];
    return true;
}

//求顶点v到各个顶点的最短路径
void NetTopo::ShortestPath(int v,int dist[],int path[])
{
    int n=numVertices;
    bool *S=new bool[n];//最短路径顶点集
    //int i,j,k;
    int w,min;
    for(int i=0;i<n;++i)
    {
        dist[i]=getWeight(v,i);//最短路径长度数组初始化
        S[i]=false;

        if(i!=v&&dist[i]<inf)
            path[i]=v;  //保存该顶点的前一个顶点
        else
            path[i]=-1;
    }
    S[v]=true;  //将顶点v加入顶点集
    dist[v]=0;
    for(int i=0;i<n-1;i++)
    {
        min=inf;
        int u=v;
        //选取不在最短路径顶点集S中的顶点
        for(int j=0;j<n;j++)
        {
            if(!S[j]&&dist[j]<min)
            {
                u=j;min=dist[j];
            }
        }
        S[u]=true;
        for(int k=0;k<n;++k)
        {
            w=getWeight(u,k);
            //用到顶点u的最短路径长度去更新其他未找到最短路径长度的点
            if(!S[k]&&w<inf&&dist[u]+w<dist[k])
            {
                dist[k]=dist[u]+w;//更新最短路径长度
                path[k]=u;  //修改到k的最短路径
            }
        }
    }
}
//打印路由表
void NetTopo::printRoutingTable(int v,int dist[],int path[])
{
    /*
    for(int i=0;i<numVertices;++i)
    {
        for(int j=0;j<numVertices;++j)
            cout<<Edge[i][j]<<' ';
        cout<<endl;
    }
    for(int i=0;i<numVertices;++i)
        cout<<path[i]<<' ';
    cout<<endl;*/

    cout<<"路由器"<<VerticesList[v]<<"的路由表如下："<<endl;
    cout<<"\t目的网络"<<"\t下一跳"<<endl;
    for(int i=0;i<numVertices;++i)
    {
        if(i!=v)
        {
            int k=i;
            while(path[k]!=v)
            {
                k=path[k];
            }
            cout<<"\t  "<<VerticesList[i]<<"\t\t  "<<VerticesList[k]<<endl;
        }
    }
}
