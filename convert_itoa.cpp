//把整数赋值给数组
 
#include<iostream>
using namespace std;

const int maxn = 100;

int convert_itoa(int array[],int num)
{
	int len_of_num = 0;
	int num_ = num;
	while(num_){
		num_/=10;
		len_of_num++;
	} 
	
	for(int i=len_of_num-1;i>=0;i--)
	{
		array[i] = num%10;
		num/=10;
	}
}

int main()
{
	return 0;
}
