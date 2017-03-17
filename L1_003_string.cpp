//L1_003 net

#include<iostream>
#include<string>

using namespace std;
/*
	input:
		in_number:���������е�����
		number:��Ҫ��ѯ������0-9
	output:
		number��in_number�г��ֵĴ��� 
*/
int get_number_times(string& in_number, int number)
{
	int count=0;
	for(int i=0;i<in_number.length();i++)
	{
		if(in_number[i] == (char)(number + 48))	//ascii���գ�
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
