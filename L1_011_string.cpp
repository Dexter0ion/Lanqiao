//������⺯�� 
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string A;
	string B;
	
	//���ж�ȡ
	getline(cin,A);
	getline(cin,B);
	//����A�ַ����е�ÿһ���ַ�
	for(char charitem = begin(A); charitem<end(A);)
	{
		if(B.find(*charitem)!=-1)//�����ҵ�Ϊ�ж�����  �ҵ��ظ��ģ���һ�����п����ظ�
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
