#include<iostream>
#include<vector>
using namespace std;
class NetTopo
{
public:
    NetTopo(){}
    //void createTopo();//建立拓扑图
    bool insertVertex(int v);//插入顶点
    bool insertEdge(int v1,int v2,int cost);//插入边(v1,v2),权值为cost
    bool removeVertex(int v);//删除顶点v及相关的边
    bool removeEdge(int v1,int v2);//删除边(v1,v2)
private:
    int maxVertices;//拓扑中最大顶点数
    int numEdges;//当前拓扑中的边数
    int numVertices;//当前拓扑中中的顶点数
    vector<vector<int> > G;
};
