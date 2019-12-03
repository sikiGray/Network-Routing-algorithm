#include<iostream>
#include<fstream>
#include"NetTopo.h"
using namespace std;
int main(void)
{
    int i,j,cost;
    int dist[100];
    int path[100];
    NetTopo G;
    ifstream fin;
    fin.open("NetTopo.txt",ios::in);
    for(int k=0;k<7;++k)
        G.insertVertex(k);
    while(fin>>i>>j>>cost)
    {
        G.insertEdge(G.getVertexPos(i),G.getVertexPos(j),cost);
    }
    while(1)
    {
        int t;
        cout<<"请输入要查询路由表的路由器号：";
        cin>>t;
        int v=G.getVertexPos(t);
        if(v==-1)
        {
            cout<<"不存在此路由器！"<<endl;
            continue;
        }
        //cout<<v<<endl;
        G.ShortestPath(v,dist,path);
        //cout<<1<<endl;
        G.printRoutingTable(v,dist,path);
    }

}
