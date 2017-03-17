//æÿ’Û≥À∑®
//martrix multiplication

#include<iostream>
#include<string.h>
#define maxn 201
using namespace std;
int main()
{
	int m,s,n;
	int c1[maxn][maxn];
	int c2[maxn][maxn];
	int c3[maxn][maxn];
	memset(c3,0,sizeof(c3));
	cin>>m>>s>>n;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<s;j++)
			cin>>c1[i][j];
	
	for(int i=0;i<s;i++)
		for(int j=0;j<n;j++)
			cin>>c2[i][j];
	
//c3[2][2] = c1[2][0]*c2[0][2]+c1[2][1]*c2[1][2]+....+c1[2][s]*c2[s][2];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<s;k++)
					c3[i][j]+=c1[i][k]*c2[k][j];		
	
	for(int i=0;i<m;i++){ 
		for(int j=0;j<n;j++)
			cout<<c3[i][j]<<" ";	
		cout<<endl; 
	}
	
	return 0; 
 } 
