//蓝桥杯 数列排序
//初次用快排函数 
//coded by dexion 

#include<stdio.h> 
#include<stdlib.h>

#define maxn 300
//升序 
int compInc(const void*a,const void*b)
{
	return *(int *)a - *(int *)b;
 } 

//降序
int compDec(const void*a,const void *b)
{
	return *(int *)b - *(int *)a;
}
 
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	int num[maxn];
 	int i;
 	for(i=0;i<n;i++)
 		scanf("%d",&num[i]);
 	qsort(num,n,sizeof(num[0]),compInc);
 	for(i=0;i<n;i++)
 		printf("%d ",num[i]);
 	
 	return 0;
 	
 }
