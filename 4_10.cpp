//���ű����Ľ� ��ʮ�� ����������
//���
#include<iostream>
#define maxn 50001
using namespace std;
int main()
{
	int n=0;
	int count=0;
	int a[maxn];
	int L,R;//L RΪ������ֹλ����
	int min,max;
	cin>>n;	//nΪȫ���еĹ�ģ
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	for(L=1;L<=n;L++)
	{
		min = max = a[L];
		for(R=L;R<=n;R++)
		{
			if(min>a[R])
			{
				min = a[R];
			}
			if(max<a[R])
			{
				max = a[R];
			}
			
			if(max-min==R-L)
				count++;
		}
		
	}
	
	cout<<count;
	return 0;
 } 
