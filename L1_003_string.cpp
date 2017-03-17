//L1_003 net

#include<iostream>
#include<string>

using namespace std;
/*
	input:
		in_number:输入样例中的数字
		number:需要查询的数字0-9
	output:
		number在in_number中出现的次数 
*/
int get_number_times(string& in_number, int number)
{
	int count=0;
	for(int i=0;i<in_number.length();i++)
	{
		if(in_number[i] == (char)(number + 48))	//ascii对照？
		{
			count++; 
		} 
	 } 
	 return count;
}

int main()
{
	string input_number;
	cin>>input_number;
	int number_times[10];
	
	for(int i=0;i<10;i++)
	{
		number_times[i] = get_number_times(input_number,i);
	}
	
	for(int i=0;i<10;i++)
	{
		if(number_times[i]!=0)
		{
			cout<<i<<":"<<number_times[i]<<endl;
		}
	}
	return 0;
}
