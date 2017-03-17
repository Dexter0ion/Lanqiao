//巧用类库函数 
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string A;
	string B;
	
	//按行读取
	getline(cin,A);
	getline(cin,B);
	//遍历A字符串中的每一个字符
	for(char charitem = begin(A); charitem<end(A);)
	{
		if(B.find(*charitem)!=-1)//不以找到为判断条件  找到重复的，下一个还有可能重复
		{
			A.erase(charitem,charitem+1);
		}
		else
		{
			charitem++;
		}
	 } 
	 
	 cout<<A;
}
