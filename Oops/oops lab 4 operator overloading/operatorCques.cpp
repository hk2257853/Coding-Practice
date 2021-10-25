#include <iostream>
using namespace std;

class calc
{
public:
    void addten(int &x, int &y)
    {
        x=x+10;
        y=y+10;
    }
};

int main()
{
    calc cal;
    int a, b;
    cout << "Enter first digit\n";
    cin >> a;
    cout << "Enter second digit\n";
    cin >> b;

    cout << "Values after adding 10: " << endl;
    cal.addten(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}

