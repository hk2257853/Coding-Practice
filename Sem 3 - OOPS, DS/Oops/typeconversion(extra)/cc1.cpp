#include "iostream"
using namespace std;

// using constructor
// program doesn't work if I forward declare a class. forward declare means I declare a class but don't define it.

class sec
{
    int secs = 60; // hardcoding for testing.

public:
    int returnsec()
    {
        return secs;
    }
};

class minute
{
    int min;

public:
    minute() {}
    minute(sec &a) // need to pass by reference
    {
        min = a.returnsec() * 60; // I tried to do using friend but didn't work
    }

    void display()
    {
        cout << "Time in min: " << min << endl;
    }
};

int main()
{
    minute mintime;
    sec sectime;
    mintime = sectime;
    mintime.display();

    return 0;
}
