//蓝桥杯第四届 第十题 连号区间数
//穷举
#include<iostream>
#define maxn 50001
using namespace std;
int main()
{
	int n=0;
	int count=0;
	int a[maxn];
	int L,R;//L R为区间起止位序列
	int min,max;
	cin>>n;	//n为全排列的规模
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	for(L=1;L<=n;L++)
	{
		min = max = a[L];
		for(R=L;R<=n;R++)
		{
			if(min>a[R])
			{
				min = a[R];
			}
			if(max<a[R])
			{
				max = a[R];
			}
			
			if(max-min==R-L)
				count++;
		}
		
	}
	
	cout<<count;
	return 0;
 } 
