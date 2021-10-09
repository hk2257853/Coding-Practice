#include <iostream>
using namespace std;

class calc
{
    private:
    int x,y;

    public:
    calc() //default
    {
    cout<<"This program prints the sum"<<endl;
    }
    calc(int a,int b) //parameterised
    {
    x=a;
    y=b;
    cout<<"Sum is: "<<x+y;
    }
};

int main()
{
    calc b;
    int x,y;
    cout<<"Enter first value"<<endl;
    cin>>x;
    cout<<"Enter second value"<<endl;
    cin>>y;
    calc a(x,y);

    return 0;
}

//the values need to be passes from object for constructor. Can't use getters and setter for that.
