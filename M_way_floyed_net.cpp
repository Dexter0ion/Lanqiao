//floyed算法，时间复杂度高，但代码简单，可以处理负边，但图中不能包含负权回路  
//可以求任意一点到另外一点的最短路，而不只是源点唯一  
  
#include <iostream>  
#include <string.h>  
#include <queue>  
using namespace std;  
const int maxNodeNum=110;//最多节点个数  
const int maxEdgeNum=10010;//最多边条数  
const int inf=0x3f3f3f3f;  
int nodeNum,edgeNum;//节点，有向边个数  
int mp[maxNodeNum][maxNodeNum];//建立邻接矩阵  
  
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
        memset(mp,inf,sizeof(mp));//初始化  
        for(int i=1;i<=edgeNum;i++)//无向图，一条无向边看为两条有向边  
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
