#include "iostream"
using namespace std;

//using constructor

//Since I didn't write this it was giving me an error. class minute needs sec's object
//program doesn't work if I forward declare a class.

class sec
{
    int secs = 60; //hardcoding for testing.

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
    minute(sec &a)
    {
        min = a.returnsec() * 60; //I tried to do using friend but didn't work
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
