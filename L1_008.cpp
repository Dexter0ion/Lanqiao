#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    int count = 0;
    int sum = 0;
    for (int i = A; i <=B; i++)
    {
        sum += i;
        count++;
        cout <<setw(5)<< i;
        if (count%5==0)
        {
            cout << endl;
        }
        else if (i==B)
        {
            cout << endl;
        }
    }
    cout << "Sum = " << sum << endl;
	
}
