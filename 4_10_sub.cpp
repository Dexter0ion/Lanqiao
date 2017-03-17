#include<iostream>
#define maxn 50001
using namespace std;

int main()
{
	int N=0;
	cin>>N;
	int a[maxn];
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
	}
	int L,R;	//Z(L,R)
	int min,max;
	int count=0;
	for(L=1;L<=N;L++)
	{
		min = max = a[L];
		for(R=L;R<=N;R++)
		{
			if(a[R]<min)min=a[R];
			if(a[R]>max)max=a[R];
			if(max-min==R-L)count++;
		}
	}
	cout<<count<<endl;
	return 0;
	
}
