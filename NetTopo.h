#include<iostream>
#include<vector>
using namespace std;
const int DefaultVertices=200;  //默认的拓扑的最大顶点数
class NetTopo
{
public:
    NetTopo(int sz=DefaultVertices);//构造函数
    //void createTopo();//建立拓扑图

    bool insertVertex(int v);//插入顶点
    int getVertexPos(int v);//给出顶点在顶点表中的下标
    int getWeight(int v1,int v2);//返回边(v1,v2)上的权值，若存在顶点不在图中，则函数返回0
    bool insertEdge(int v1,int v2,int cost);//插入边(v1,v2),权值为cost
    bool removeVertex(int v);//删除顶点v及相关的边
    bool removeEdge(int v1,int v2);//删除边(v1,v2)
    void ShortestPath(int v,int dist[],int path[]);//求顶点v到各个顶点的最短路径
    void printRoutingTable(int v,int dist[],int path[]);//打印路由器v的路由表
private:
    int *VerticesList;//顶点表
    int **Edge;//邻接矩阵
    int maxVertices;//拓扑中最大顶点数
    int numEdges;//当前拓扑中的边数
    int numVertices;//当前拓扑中中的顶点数
};
