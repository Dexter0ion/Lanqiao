//���в��� net

#include<iostream>   
#include<cstdlib>   
#include<queue>  
#include<cstring>   
  
using namespace std;  
queue <int> q;  
int main()    
{    
    int n,m,t,k=0,flag=1;//k����ͳ��Ҫ��ӡ�ַ����ĸ�����nΪ���������m��t������ʱ�������������һ��no��flag��Ϊ0  
    char *s=new char;//s������itoa�е�һ��������ע��һ��Ҫ����ռ�  
    string a[51];//����Ҫ��ӡ���ַ���  
    cin>>n;  
    for(int i=0;i<n;i++)  
    {  
        cin>>m;  
        if(m==1)//������Ϊ1  
        {  
            cin>>t;  
            q.push(t);  
        }  
        if(m==2)//������Ϊ2  
        {  
            if(q.empty()&&flag)//ע��һ��Ҫ��flag�ж�  
            {  
                a[k++]="no";  
                flag=0;  
            }  
            else  
            {  
                if(flag)  
                {  
                    a[k++]=itoa(q.front(),s,10);  
                    q.pop();  
                }  
            }  
        }  
        if(m==3)  
        {  
            if(flag)  
                a[k++]=itoa(q.size(),s,10);           
        }  
    }  
    for(int i=0;i<k;i++)  
        cout<<a[i]<<endl;     
    return 0;  
}    
