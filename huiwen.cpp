#include<iostream>
#include<stdio.h>
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
	int n;
	cin>>n;

	int five[5];
	int six[6];
	/*
	convert_itoa(six,n);
	for(int i=0;i<6;i++)
	{
		cout<<six[i];
	}
	*/
	for(int i=10000;i<100000;i++)
	{
		int temp=i;
		convert_itoa(five,temp);
		/*
		for(int i=0;i<5;i++)
			cout<<five[i];
		cout<<endl;
		*/
		if(five[0]==five[4]&&five[1]==five[3])
		{
			int sum_temp=0;
			for(int j=0;j<5;j++)
			{
				sum_temp+=five[i];
			}
			
			if(sum_temp==n)
			{
				for(int k=0;k<5;k++)
				{
					cout<<five[k];	
				}	
				cout<<endl;
			}
		}	
	}
	/*
	for(int i=100000;i<1000000;i++)
	{
		convert_itoa(six,i);
		if(six[0]==six[5]&&six[1]==six[4]&&six[2]==six[3])
		{
			int sum_temp=0;
			for(int j=0;i<6;j++)
			{
				sum_temp+=six[i];
			}
			if(sum_temp==n)
			{
				for(int k=0;k<6;k++)
				{
					cout<<six[k];
				}
				cout<<endl;
			}
			  
		}
	}
*/
	return 0;
 } 
