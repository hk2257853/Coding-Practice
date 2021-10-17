#include "iostream"
using namespace std;

class minute
{
    int min = 10; //hard coded for testing. Should use contructor or set function to set the value.

public:
    minute() {}
    operator int()
    {
        return min * 60;
    }

    void display()
    {
        cout << "Time in min: " << min << endl;
    }
};

int main()
{
    minute time;
    int sec;
    sec = time;
    cout << sec;
    return 0;
}
