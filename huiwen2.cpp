#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	for(int i=10000;i<100000;i++)
	{
		int temp=i;
		int q=temp%10;
		int w=temp/10%10;
		int e=temp/100%10;
		int r=temp/1000%10;
		int t=temp/10000; 
		
		if(q==t&&w==r&&q+w+e+r+t==n)
		{
			cout<<i<<endl;
		 } 
	}
	
	for(int i=100000;i<1000000;i++)
	{
		int temp=i;
		int q=temp%10;
		int w=temp/10%10;
		int e=temp/100%10;
		int r=temp/1000%10;
		int t=temp/10000%10;
		int y=temp/100000;
		
		if(q==y&&w==t&&e==r&&q+w+e+r+t+y==n)
			cout<<i<<endl; 
	}
	return 0;
 } 
