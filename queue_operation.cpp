//¶ÓÁÐ²Ù×÷

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
				cout<<q.front()<<endl;
				q.pop();
			}
			if(q.empty())
			{
				cout<<"no"<<endl;
			}
			
		}
		
		if(cmd==3)
		{
			cout<<q.size()<<endl;
		}
		N--;
	} 
	
	return 0;
 } 
