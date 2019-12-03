#include<iostream>
#include"NetTopo.h"
using namespace std;
//const int DefaultVertices=200;  //Ĭ�ϵ����˵���󶥵���
const int inf=1000;//���Ȩֵ
//���캯��
NetTopo::NetTopo(int sz)
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
        Edge[i][j]=((i==j)? 0:inf);
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

//���������ڶ�����е��±�
int NetTopo::getVertexPos(int v)
{
    for(int i=0;i<numVertices;++i)
    {
        if(VerticesList[i]==v)
            return i;
    }
    return -1;
}

//���ر�(v1,v2)�ϵ�Ȩֵ�������ڶ��㲻��ͼ�У���������0
int NetTopo::getWeight(int v1,int v2)
{
    if(v1!=-1&&v2!=-1)
        return Edge[v1][v2];
    return 0;
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
        Edge[v][i]=Edge[numVertices][i];
    return true;
}

//�󶥵�v��������������·��
void NetTopo::ShortestPath(int v,int dist[],int path[])
{
    int n=numVertices;
    bool *S=new bool[n];//���·�����㼯
    //int i,j,k;
    int w,min;
    for(int i=0;i<n;++i)
    {
        dist[i]=getWeight(v,i);//���·�����������ʼ��
        S[i]=false;

        if(i!=v&&dist[i]<inf)
            path[i]=v;  //����ö����ǰһ������
        else
            path[i]=-1;
    }
    S[v]=true;  //������v���붥�㼯
    dist[v]=0;
    for(int i=0;i<n-1;i++)
    {
        min=inf;
        int u=v;
        //ѡȡ�������·�����㼯S�еĶ���
        for(int j=0;j<n;j++)
        {
            if(!S[j]&&dist[j]<min)
            {
                u=j;min=dist[j];
            }
        }
        S[u]=true;
        for(int k=0;k<n;++k)
        {
            w=getWeight(u,k);
            //�õ�����u�����·������ȥ��������δ�ҵ����·�����ȵĵ�
            if(!S[k]&&w<inf&&dist[u]+w<dist[k])
            {
                dist[k]=dist[u]+w;//�������·������
                path[k]=u;  //�޸ĵ�k�����·��
            }
        }
    }
}
//��ӡ·�ɱ�
void NetTopo::printRoutingTable(int v,int dist[],int path[])
{
    /*
    for(int i=0;i<numVertices;++i)
    {
        for(int j=0;j<numVertices;++j)
            cout<<Edge[i][j]<<' ';
        cout<<endl;
    }
    for(int i=0;i<numVertices;++i)
        cout<<path[i]<<' ';
    cout<<endl;*/

    cout<<"·����"<<VerticesList[v]<<"��·�ɱ����£�"<<endl;
    cout<<"\tĿ������"<<"\t��һ��"<<endl;
    for(int i=0;i<numVertices;++i)
    {
        if(i!=v)
        {
            int k=i;
            while(path[k]!=v)
            {
                k=path[k];
            }
            cout<<"\t  "<<VerticesList[i]<<"\t\t  "<<VerticesList[k]<<endl;
        }
    }
}
