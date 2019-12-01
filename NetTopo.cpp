#include<iostream>
using namespace std;
const int DefaultVertices=200;  //Ĭ�ϵ����˵���󶥵���
const int inf=1e7;//���Ȩֵ
//���캯��
NetTopo::NetTopo(int int sz=DefaultVertices)
{
    maxVertices=sz;//������󶥵���
    numVertices=0;//��ǰ����������Ϊ0
    numEdges=0;//��ǰ��������Ϊ0
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
//���������ڶ�����е��±�
int NetTopo::getVertexPos(int v)
{
    for(int i=0;i<numVertices;++i)
    {
        if(VerticesList[i]==v)
            return i;
        return -1;
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
//ɾ����(v1,v2)
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
//ɾ���ڵ�v����صı�
bool NetTopo::removeVertex(int v)
{
    if(v<0||v>numVertices)//����v������ͼ��
        return false;
    if(numVertices==1)//��ֻʣһ������ʱ��������ɾ��
        return false;
    VerticesList[v]=VerticesList[numVertices-1];//���ȴӶ������ɾ���ö���

    //���¼��㵱ǰ�����еı�������ȥ�ٵ��ıߣ�
    for(int i=0;i<numVertices;++i)
    {
        if(Edge[i][v]>0&&Edge[i][v]<inf)
            numEdges--;
    }
    //ʹ�����һ�����v��
    for(int i=0;i<numVertices;++i)
        Edge[i][v]=Edge[i][numVertices-1];
    numVertices--;
    //ʹ�����һ�����v��
    for(int i=0;i<numVertices;++i)
        Edge[v][i]=Edge[i][numVertices][i];
    return true;
}
