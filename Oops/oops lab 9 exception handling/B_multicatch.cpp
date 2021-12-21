#include "iostream"
using namespace std;

int main()
{
    float a, b;
    cout << "Enter numbers:" << endl;
    cin >> a >> b;

    try
    {
        if (b != 0)
            cout << "Division is: " << a / b;
        else
            throw(b);
    }
    catch (int i)
    {
        cout << "Caught exception: int type" << endl;
    }
    catch (double d)
    {
        cout << "Caught exception: double type" << endl;
    }
    catch (float f)
    {
        cout << "Caught exception: float type" << endl;
    }
}