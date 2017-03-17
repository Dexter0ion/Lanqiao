#include <iostream>  
#include<string>  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */  
using namespace std;  
int main(int argc, char** argv) {  
    string a,b,c,t;  
    cin>>a>>b>>c;  
    if(a.length()>b.length()||(a.length()==b.length()&&a>b)){  
        t=a;a=b;b=t;  
    }  
    if(a.length()>c.length()||(a.length()==c.length()&&a>c)){  
        t=a;a=c;c=t;  
    }  
    if(b.length()>c.length()||(b.length()==c.length()&&b>c)){  
        t=b;b=c;c=t;  
    }  
    cout<<a<<"->"<<b<<"->"<<c<<endl;  
    return 0;  
}  
