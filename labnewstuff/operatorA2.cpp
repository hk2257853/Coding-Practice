#include "iostream"
using namespace std;

class unary
{
private:
    int x;

public:
    unary(){}
    unary(int a)
    {
        x=a;
    }

    unary operator++ () //after removing int as paramenter it worked!! understand this topic further
    {
        unary temp;
        temp.x=++x;
        return temp;
    }
    void Display()
    {
        cout<<"x: "<<x<<endl;
    }


};

int main()
{
    unary c1(5);
    ++c1;
    c1.Display();


    return 0;
}
