#include "iostream"
using namespace std;
//ref without using function
int main()
{
    int a=5,b=6;
    cout<<"Enter 1st value:\n";
    cin>>a;
    cout<<"Enter 2st value:\n";
    cin>>b;
   // int n1,n2; doesn't work

    //&n1=&a;
    //&n2=b;
    cout<<"The values are\n";
    int &n1=a;
    int &n2=b;


    cout<<n1<<endl;
    cout<<n2<<endl;


return 0;
}
