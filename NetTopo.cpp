#include<iostream>
using namespace std;
const int DefaultVertices=200;  //默认的拓扑的最大顶点数
const int inf=1e7;//最大权值
//构造函数
NetTopo::NetTopo(int int sz=DefaultVertices)
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
        Edge[i][j]=(i==j)? 0:inf;
    }
}
//给出顶点在顶点表中的下标
int NetTopo::getVertexPos(int v)
{
    for(int i=0;i<numVertices;++i)
    {
        if(VerticesList[i]==v)
            return i;
        return -1;
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
        Edge[v][i]=Edge[i][numVertices][i];
    return true;
}
