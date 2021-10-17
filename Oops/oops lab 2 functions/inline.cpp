#include <iostream>
using namespace std;

class calc
{
public:
inline int product(int a, int b)
{
    return a*b;
}
};

calc cal;

int main()
{
cout<<cal.product(5,6)<<"\n";
cout<<cal.product(12,6)<<"\n";
cout<<cal.product(7,8)<<"\n";
cout<<cal.product(4,7)<<"\n";
cout<<cal.product(2,1)<<"\n";

return 0;
}
