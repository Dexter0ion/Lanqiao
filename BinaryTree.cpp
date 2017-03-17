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
	int v,id,ak;	//v是value,存储节点的值 ,ak存储字符数组a的长度
	char a[10];	 
}Nodes[maxn];

char map[maxn][maxn];
char a='.',b = '-',c = '|',d = '\0';

void BinaryTree_set(int rt,int k)
{
	//set构造二叉排序树,rt表示根节点
	if(Nodes[k].v>Nodes[rt].v)
	{
		Nodes[rt].right_s++;	//s,sum的缩写，表示此节点的右子树节点个数
		if(Nodes[rt].right != -1)	
		{
			BinaryTree_set(Nodes[rt].right,k);	//递归进入右子树进行比较
			
		 }
		else
		{
			//当给的k下标的值大于根的值，且根没有右子树
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

void Map_set(int k,int index)		//图的构造，index定位字符串结尾'\0'的位置 
{
	for(int i=0;i<Nodes[k].ak;i++)
	{
		map[Nodes[k].id][index+i] = Nodes[k].a[Nodes[k].ak -1-i];//进行节点的值的填充
		 
	}
	
	index += Nodes[k].ak;	//字符串的结束下标要在值的后面，所以加a的长度
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
	istringstream ss(s); //ss可以任意取名 中断提取字符串 提取到e 
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
		
		while(e) //将 e(value)的值存储在字符串中 
		{
			Nodes[i].a[Nodes[i].ak] = e%10 +'0';
			Nodes[i].ak++;
			e /= 10; 
		}
	}
		for(int i=1;i<n;i++)
		{
			BinaryTree_set(0,i);	//生成n-1个分支 
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
