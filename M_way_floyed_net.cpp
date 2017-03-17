//floyed�㷨��ʱ�临�Ӷȸߣ�������򵥣����Դ����ߣ���ͼ�в��ܰ�����Ȩ��·  
//����������һ�㵽����һ������·������ֻ��Դ��Ψһ  
  
#include <iostream>  
#include <string.h>  
#include <queue>  
using namespace std;  
const int maxNodeNum=110;//���ڵ����  
const int maxEdgeNum=10010;//��������  
const int inf=0x3f3f3f3f;  
int nodeNum,edgeNum;//�ڵ㣬����߸���  
int mp[maxNodeNum][maxNodeNum];//�����ڽӾ���  
  
void floyed()  
{  
    for(int k=1;k<=nodeNum;k++)  
        for(int i=1;i<=nodeNum;i++)  
            for(int j=1;j<=nodeNum;j++)  
                if(mp[i][k]+mp[k][j]<mp[i][j])  
                    mp[i][j]=mp[i][k]+mp[k][j];  
}  
  
int main()//140MS  
{  
    while(cin>>nodeNum>>edgeNum&&(nodeNum||edgeNum))  
    {  
        int from,to,w;  
        memset(mp,inf,sizeof(mp));//��ʼ��  
        for(int i=1;i<=edgeNum;i++)//����ͼ��һ������߿�Ϊ���������  
        {  
            cin>>from>>to>>w;  
            if(w<mp[from][to])  
                mp[from][to]=mp[to][from]=w;  
        }  
        floyed();  
        cout<<mp[1][nodeNum]<<endl;  
    }  
    return 0;  
}  
