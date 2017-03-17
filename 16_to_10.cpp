//À¶ÇÅ±­ Ê®Áù×ªÊ® 

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	string hex;
	long long dec = 0;
	cin >> hex;
	int len = hex.length() ;
	for(int i=0;i<len;i++)
	{
		if(hex[i] >= 'A')
		{
			dec += (hex[i] - 'A'+10)*pow(16,len-i-1);
			//printf("%d\n",hex[i]- 'A');	
		}
		else
		{
			dec += (hex[i] - '0')*pow(16,len-1-i);
		}
	}
	cout<<dec;
	return 0;
 } 
