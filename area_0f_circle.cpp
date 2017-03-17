//À¶ÇÅ±­ Ô²µÄÃæ»ý
//coded by dexion

#include<stdio.h>
#include<cmath>
int main()
{
	double PI = atan(1.0)*4;
	double area = 0;
	double radius = 0;
	
	scanf("%lf",&radius);
	area = PI*radius*radius;
	printf("%.7lf",area);
	//printf("%.7f",PI);
}
