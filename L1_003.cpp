#include<iostream>
#include<string.h>
#include<math.h>
#define maxn 1001
using namespace std;

int main()
{
		int N;
		cin>>N;
		int num_t = N;
		int num[maxn]; 
		int cnt[maxn];
		memset(num,0,sizeof(num));
		memset(cnt,0,sizeof(cnt));
		int len=0;
		//获取整数长度
		while(num_t)
		{
			num_t/=10;
			len++;
		}
		//cout<<len<<endl;
		//长度内获取数字 插入数组 
		for(int i=0;i<len;i++)
		{
			int t = N%10;
			for(int j=0;j<len;j++)
			{
				if()
			}
		}
} 
