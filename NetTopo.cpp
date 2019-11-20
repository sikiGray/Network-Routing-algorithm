#include<iostream>
using namespace std;
const int DefaultVertices=200;  //默认的拓扑的最大顶点数
const int inf=1e7;
//构造函数
NetTopo::NetTopo(int int sz=DefaultVertices)
{
    maxVertices=sz;
    numVertices=0;
    numEdges=0;
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
