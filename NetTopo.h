#include<iostream>
#include<vector>
using namespace std;
const int DefaultVertices=200;  //Ĭ�ϵ����˵���󶥵���
class NetTopo
{
public:
    NetTopo(int sz=DefaultVertices);
    //void createTopo();//��������ͼ
    bool insertVertex(int v);//���붥��
    bool insertEdge(int v1,int v2,int cost);//�����(v1,v2),ȨֵΪcost
    bool removeVertex(int v);//ɾ������v����صı�
    bool removeEdge(int v1,int v2);//ɾ����(v1,v2)
private:
    int *VerticesList;//�����
    int **Edge;//�ڽӾ���
    int maxVertices;//��������󶥵���
    int numEdges;//��ǰ�����еı���
    int numVertices;//��ǰ�������еĶ�����
};
