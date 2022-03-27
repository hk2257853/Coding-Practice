#include <iostream>
using namespace std;

template <class T>
void swapelements(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i1 = 5, i2 = 10;
    cout << "i1 is: " << i1 << ", i2 is: " << i2 << endl;
    swapelements<int>(i1, i2);
    cout << "i1 is: " << i1 << ", i2 is: " << i2 << endl;
    string s1 = "hi", s2 = "there";
    cout << "s1 is: " << s1 << ", s2 is: " << s2 << endl;
    swapelements<string>(s1, s2);
    cout << "s1 is: " << s1 << ", s2 is: " << s2 << endl;
    float f1 = 5.0, f2 = 10.0;
    cout << "f1 is: " << f1 << ", f2 is: " << f2 << endl;
    swapelements<float>(f1, f2);
    cout << "f1 is: " << f1 << ", f2 is: " << f2 << endl;
}

