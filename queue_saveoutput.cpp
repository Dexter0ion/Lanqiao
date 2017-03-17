//队列操作 存储输出

#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>

using namespace std;
queue <int> q;
int main()
{
	int cmd;
	int num;
	int N;
	int k=0;
	char *s = new char;	//s用来当itoa中的一个参数，注意一定要申请空间
	string a[51];	//存储要答应的字符串 
	cin>>N;
	
	while(N)
	{
		cin>>cmd;
		if(cmd==1)
		{
			cin>>num;
			q.push(num);
		}
		if(cmd==2)
		{
			if(!q.empty())
			{
				a[k++]=itoa(q.front(),s,10);
				q.pop();
			}
			if(q.empty())
			{
				a[k++]="no";
			}
		}
		if(cmd==3)
		{
			a[k++]=itoa(q.size(),s,10);
		}
		N--;
	 } 
	 
	 for(int i=0;i<k;i++)
	 {
	 	cout<<a[i]<<endl;
	 }
	 
	 return 0;
 } 
