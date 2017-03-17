//¿∂«≈±≠ fibonacci»°”‡
//coded by dexion
#include<stdio.h>

int main()
{
	unsigned long f1 = 1,f2 = 1,f3=1;
	long n=0;
	long s;
	
	scanf("%ld",&n);
	
	if(n>=3)
	{
		for(s=3;s<=n;s++)
		{
			f3 = (f2+f1)%10007;
			f1 = f2;
			f2 = f3;
		}
	}
	
	printf("%ld",f3);
	return 0;
 } 
