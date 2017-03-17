#include<iostream>
using namespace std;

int book[256];
int main()
{
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin,s2);
	int l1=s1.length();
	int l2=s2.length();
	
	for(int i=0;i<l1;i++)
	{
		//用ascii码表示s2出现的字符
		book[s2[i]]=1; 
	}
	
	for(int i=0;i<l1;i++)
	{
		if(book[s1[i]]==1)
		{
			continue;
		}
		cout<<s1[i];
	}
} 
