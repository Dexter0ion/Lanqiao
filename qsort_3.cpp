//À¶ÇÅ±­ ÈıÊı×ÖÅÅĞò 
//³õ´ÎÓÃ¿ìÅÅº¯Êı 
//coded by dexion 

#include<stdio.h> 
#include<stdlib.h>

#define maxn 300
//ÉıĞò 
int compInc(const void*a,const void*b)
{
	return *(int *)a - *(int *)b;
 } 

//½µĞò
int compDec(const void*a,const void *b)
{
	return *(int *)b - *(int *)a;
}
 
 int main()
 {
 	int num[maxn];
 	int i;
 	for(i=0;i<3;i++)
 		scanf("%d",&num[i]);
 	qsort(num,3,sizeof(num[0]),compDec);
 	for(i=0;i<3;i++)
 		printf("%d ",num[i]);
 	
 	return 0;
 	
 }
