//蓝桥杯 十六进制转八进制
//用枚举试试 不了 

#include<stdio.h>
#include<string.h> 
#include<cmath>

#define maxn 20

 
int main()
{
	int num_16[maxn];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%x",&num_16[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%o\n",num_16[i]);
	}
	return 0;
}
