//test_istringstream

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	string str = "i love u";
	istringstream aaaa(str);
	string s;
	while(aaaa>>s)
	{
		cout<<s<<endl; 
	} 
	
}
