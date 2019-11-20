#include<iostream>
using namespace std;
const int DefaultVertices=200;  //默认的拓扑的最大顶点数
const int inf=1e7;
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
