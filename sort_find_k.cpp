//区间k大数查询

#include<iostream>
#include<stdlib.h>

using namespace std;

int compDec(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

#define maxn 1001 
int main()
{
	int n;	//序列长度
	cin>>n;
	
	int num[maxn];

	for(int i=0;i<n;i++)
	{
		cin >> num[i];
	}	
		
	int m;	//询问个数
	cin>>m;
	int t = m;	
	int num_new[maxn];
	int num_k[maxn];
	while(t>0)
	{
		int l,r,k;
		cin>>l>>r>>k;	//l到r从左往右 第K大
		int cnt=l-1;
		int diff = r-l;
		for(int i=0;i<=diff;i++)	//+1 or not
		{
			num_new[i] = num[cnt];
			cnt++;
		}
		

		qsort(num_new,r-l+1,sizeof(num_new[0]),compDec);
		
		num_k[t] = num_new[k-1];
		
		//cout<<endl<<"num_k="<<num_k[t]<<endl; 
		t--;
	 } 
	 
	 while(m>0)
	 {
	 	cout<<num_k[m];
	 	cout<<endl;
	 	m--;
	 }
 
	 return 0;
 } 
