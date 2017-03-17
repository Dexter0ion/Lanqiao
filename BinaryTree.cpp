#include<iostream>
#include<cstdio>
#include<sstream> 
#include<cstring>

using namespace std;

const int maxn = 110;
const int maxm = 710;

struct node
{
	int left,right;
	int left_s,right_s;
	int v,id,ak;	//v��value,�洢�ڵ��ֵ ,ak�洢�ַ�����a�ĳ���
	char a[10];	 
}Nodes[maxn];

char map[maxn][maxn];
char a='.',b = '-',c = '|',d = '\0';

void BinaryTree_set(int rt,int k)
{
	//set�������������,rt��ʾ���ڵ�
	if(Nodes[k].v>Nodes[rt].v)
	{
		Nodes[rt].right_s++;	//s,sum����д����ʾ�˽ڵ���������ڵ����
		if(Nodes[rt].right != -1)	
		{
			BinaryTree_set(Nodes[rt].right,k);	//�ݹ�������������бȽ�
			
		 }
		else
		{
			//������k�±��ֵ���ڸ���ֵ���Ҹ�û��������
			Nodes[rt].right = k; 
		} 	
	}
	
	if(Nodes[k].v<=Nodes[rt].v)
	{
		Nodes[rt].left_s++;
		if(Nodes[rt].left !=-1)
		{
			BinaryTree_set(Nodes[rt].right,k);
		}
		else
		{
			Nodes[rt].left = k;
		}
	}
}

void Id_set(int rid,int k)	//	rid right_id?
{
	Nodes[k].id = rid +Nodes[k].right_s + 1;
	if(Nodes[k].right != -1)
	{
		Id_set(rid,Nodes[k].right);
	 } 
	 if(Nodes[k].left !=-1)
	 {
	 	Id_set(rid,Nodes[k].left_s);
	 }
}

void Map_set(int k,int index)		//ͼ�Ĺ��죬index��λ�ַ�����β'\0'��λ�� 
{
	for(int i=0;i<Nodes[k].ak;i++)
	{
		map[Nodes[k].id][index+i] = Nodes[k].a[Nodes[k].ak -1-i];//���нڵ��ֵ�����
		 
	}
	
	index += Nodes[k].ak;	//�ַ����Ľ����±�Ҫ��ֵ�ĺ��棬���Լ�a�ĳ���
	if(Nodes[k].left != -1||Nodes[k].right!=-1)
	{
		map[Nodes[k].id][index++] = b;
		int max,min;
		max = Nodes[k].id;
		min = Nodes[k].id;
		
		if(Nodes[k].left !=-1)
		{
			max = Nodes[Nodes[k].left].id;
			map[Nodes[Nodes[k].left].id][index+1]=b;
			Map_set(Nodes[k].left,index+2);
		}
		if(Nodes[k].right !=-1)
		{
			min = Nodes[Nodes[k].left].id;
			map[Nodes[Nodes[k].right].id][index+1]=b;
			Map_set(Nodes[k].right,index+2);
		}
		
		for(int i=min;i<max;i++)
		{
			map[i][index] = c;
		}
		map[Nodes[k].id][index+1]=d;
	 } 
	 else
	 {
	 	map[Nodes[k].id][index] = d;
	 	return;
	 }
 } 
int main()
{
	int n=0;
	int e;
	int A[maxn];
	string s;
	getline(cin,s);
	istringstream ss(s); //ss��������ȡ�� �ж���ȡ�ַ��� ��ȡ��e 
	while(ss>>e)
	{
		A[n] = e;
		n++;
	}
	
	for(int i=0;i<n;i++)
	{
		e = A[i];
		Nodes[i].left = -1;
		Nodes[i].right = -1;
		Nodes[i].left_s = 0;
		Nodes[i].right_s = 0;
		Nodes[i].ak = 0;
		Nodes[i].v = e;
		
		while(e) //�� e(value)��ֵ�洢���ַ����� 
		{
			Nodes[i].a[Nodes[i].ak] = e%10 +'0';
			Nodes[i].ak++;
			e /= 10; 
		}
	}
		for(int i=1;i<n;i++)
		{
			BinaryTree_set(0,i);	//����n-1����֧ 
		}
		Id_set(0,0);
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<maxn;j++)
			{
				map[i][j] = a;
			}
		}
		
		Map_set(0,0);
		
		for(int i=1;i<=n;i++)
		{
			cout<<map[i]<<endl;
		}
		
	
	return 0;
}
