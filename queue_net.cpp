//队列操作 net

#include<iostream>   
#include<cstdlib>   
#include<queue>  
#include<cstring>   
  
using namespace std;  
queue <int> q;  
int main()    
{    
    int n,m,t,k=0,flag=1;//k用来统计要打印字符串的个数，n为输入个数，m，t都是临时变量，若输出了一个no，flag置为0  
    char *s=new char;//s用来当itoa中的一个参数，注意一定要申请空间  
    string a[51];//储存要打印的字符串  
    cin>>n;  
    for(int i=0;i<n;i++)  
    {  
        cin>>m;  
        if(m==1)//当输入为1  
        {  
            cin>>t;  
            q.push(t);  
        }  
        if(m==2)//当输入为2  
        {  
            if(q.empty()&&flag)//注意一定要加flag判断  
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
