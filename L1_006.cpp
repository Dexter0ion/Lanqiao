//L1-006
//连续因子

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

long ans=0,leng=0;


long find(long n,long fec,long l) 
{
	//剩余被除数，因子，长度
	if(n%fec==0)
	{
		return find(n/fec,fec+1,l+1);
	 } 
	 else return l;
}

int main()
{
	long n;
	cin>>n;
	
	for(long i=2;i<sqrt(n);i++)
	{
		if(n%i==0)
		{
			int l=find(n/i,i+1,1);
			if(l>leng)
			{
				leng=l;
				ans=i;
			}
		}
	
	}
	if(leng==0)
	{
		cout<<1<<endl;
		cout<<n<<endl;
		return 0;
	}

	cout<<leng<<endl;
	for(int i=0;i<leng-1;i++)
	{
		printf("%ld*",ans+i);
	}
	printf("%ld\n",ans+leng-1);
	return 0;
}
