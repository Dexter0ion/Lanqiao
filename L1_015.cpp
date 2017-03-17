#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    int N=0;
    char C;
    cin>>N>>C;
    for(int i=0;i<( (N+1)/2 );i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<C;
        }
        cout<<endl;
    }
    return 0;
}
