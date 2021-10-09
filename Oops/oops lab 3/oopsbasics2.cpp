#include <iostream>
using namespace std;

//getter: get the value of a particular variable
//setter: set the value to the particlar/all variable
//they r more like convention then concept.

class calc
{
    private:
    int x,y;
    string color;


    public:
    string getter()
    {
    return color; //or just return x and print its value.
    }

    void setter(int a, int b, string clr)
    {
    x=a;  //or inplace of getting as parameters I can do cin
    y=b;
    color=clr;
    }

    void sum()
    {
    cout<<"Sum is: "<<x+y<<endl;
    }

    void printcolor()
    {
    cout<<color<<endl;
    }
};

int main()
{
    calc a;

    a.setter(5, 7, "blue");
    cout<<a.getter()<<endl;

    //other stuff
    a.printcolor();
    a.sum();

    return 0;
}

