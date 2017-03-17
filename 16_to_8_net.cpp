//蓝桥杯 十六转八 
//大数问题 要转二进制 字符串 
//coded by dexion
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string hex[20]; 
	long long dec[20];
	long long oxd[20];
	
	memset(dec,0,sizeof(dec));
	memset(oxd,0,sizeof(oxd));
	
	for(int i=0;i<n;i++)
	{
		cin >> hex[i];
		int len = hex[i].length();
		
		for(int j=0;j<len;j++)
		{
			if(hex[i][j]>='A')
			{
				dec[i] += (hex[i][j] - 'A'+10)*pow(16,len-j-1);	
			}
			else
			{
				dec[i] += (hex[i][j] - '0')*pow(16,len-j-1);
			}			
		}
	 } 
	 
	/* for(int i=0;i<n;i++)
	 	cout<<dec[i]<<endl;
	*/
	
	for(int i=0;i<n;i++)
	{
		int count = 0;
		while(dec[i]!=0)
		{
			oxd[i]+=dec[i]%8*pow(10,count);
			count++;
			dec[i] = dec[i]/8;
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<oxd[i]<<endl;
	return 0;
 } 
