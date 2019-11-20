#include<iostream>
using namespace std;
const int DefaultVertices=200;  //Ĭ�ϵ����˵���󶥵���
const int inf=1e7;
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
