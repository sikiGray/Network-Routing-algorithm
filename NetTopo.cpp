#include<iostream>
using namespace std;
const int DefaultVertices=200;  //Ĭ�ϵ����˵���󶥵���
const int inf=1e7;
//���캯��
NetTopo::NetTopo(int int sz=DefaultVertices)
{
    maxVertices=sz;
    numVertices=0;
    numEdges=0;
    VerticesList=new int[maxVertices];//�������������
    Edge=(int **)new int*[maxVertices];//�����ڽӾ���
    for(int i=0;i<maxVertices;++i)
        Edge[i]=new int[maxVertices];
    //�ڽӾ����ʼ��
    for(int i=0;i<maxVertices;++i)
        for(int j=0;j<maxVertices;++j)
    {
        Edge[i][j]=(i==j)? 0:inf;
    }
}
//������뺯��
bool NetTopo::insertVertex(int v)
{
    //�ж��Ƿ��п�λ��
    if(numVertices==maxVertices)
        return false;
    VerticesList[numVertices]=v;
    ++numVertices;
}
//��Ȩ�߲��뺯��
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
