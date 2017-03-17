//���·ģ��-0
//floyed

#include<iostream>
#include<string.h>//ʹ��memset(���飬��ֵ��sizeof(������)) 
using namespace std;

const int MaxNodeNum=110;	//���ڵ���� 
const int MaxEdgeNum=10010; //��������
const int inf = 0x3f3f3f3f;	//�ߵ�Ȩ��������ʼֵ
int nodeNum;
int edgeNum;

int map[MaxNodeNum][MaxNodeNum];//����ͼ��ϵ :ͼ(�ڵ㣬�ڵ㣩-ֵ

 

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
	//���벿��
	cin>>nodeNum;//����ڵ��� 
	cin>>edgeNum;//����ߵ�����
	
	int from;//������-�ڵ�1 
	int to;//Ŀ�ĵ� -�ڵ�2 
	int cost;//·��-�ߵ�ֵ 
	memset(map,inf,sizeof(map));//��ʼ������ ���ñ߳�ʼֵ
	for(int i=1;i<=edgeNum;i++)//����ͼ��һ���������Ϊ���������
	{
		cin>>from>>to>>cost;
		
		if(cost<map[from][to])
		{
			map[from][to]=map[to][from]=cost;//˫�߸�ֵ 
		}
		
	}
	floyed(); 
	cout<<map[1][nodeNum]<<endl;
	return 0;
}


