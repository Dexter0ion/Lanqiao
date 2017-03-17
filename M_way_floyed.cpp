//最短路模板-0
//floyed

#include<iostream>
#include<string.h>//使用memset(数组，赋值，sizeof(数组名)) 
using namespace std;

const int MaxNodeNum=110;	//最多节点个数 
const int MaxEdgeNum=10010; //最多边条数
const int inf = 0x3f3f3f3f;	//边的权重无穷大初始值
int nodeNum;
int edgeNum;

int map[MaxNodeNum][MaxNodeNum];//创建图关系 :图(节点，节点）-值

 

void floyed()
{
	for(int k=1;k<=nodeNum;k++)  
        for(int i=1;i<=nodeNum;i++)  
            for(int j=1;j<=nodeNum;j++)  
                if(map[i][k]+map[k][j]<map[i][j])  
                    map[i][j]=map[i][k]+map[k][j]; 
}

int main()
{
	//输入部分
	cin>>nodeNum;//输入节点数 
	cin>>edgeNum;//输入边的条数
	
	int from;//出发地-节点1 
	int to;//目的地 -节点2 
	int cost;//路程-边的值 
	memset(map,inf,sizeof(map));//初始化数组 设置边初始值
	for(int i=1;i<=edgeNum;i++)//无向图，一条无向边视为两条邮箱变
	{
		cin>>from>>to>>cost;
		
		if(cost<map[from][to])
		{
			map[from][to]=map[to][from]=cost;//双边赋值 
		}
		
	}
	floyed(); 
	cout<<map[1][nodeNum]<<endl;
	return 0;
}


