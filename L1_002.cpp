//PAT-L1-002
//´òÓ¡É³Â© 
#include<iostream>

using namespace std;

int main()
{
	int N;
	char C;
	cin>>N>>C;
	
	int sum=1;
	int rem=0;
	int round=1;
	for(int i=2;sum+2*(2*i-1)<N-1;i++)
	{
		round++; 
		sum+=2*(2*i-1);
	}

	rem = N-sum;
	
	for(int i=round;i>0;i--)
	{
		for(int j=0;j<round-i;j++)
		{
			cout<<" ";
		}
		for(int k=0;k<2*i-1;k++)
		{
			cout<<C;
		}
		
		cout<<endl;
	 } 
	 
	for(int i=2;i<round+1;i++)
	{
		for(int j=0;j<round-i;j++)
		{
			cout<<" ";
		}
		for(int k=0;k<2*i-1;k++)
		{
			cout<<C;
		}
		cout<<endl;
	 } 
	cout<<rem<<endl;
	
	return 0;
 } 
 
 /*
 *	1
 
 ***
 *
 ***	1+3+3=7	
 
 *****
 ***
 *
 ***
 *****	1+3+3+5+5 = 16+1=17
 		2*(2*2-1+2*3-1)
 */
 
