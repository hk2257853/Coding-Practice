#include "iostream"
using namespace std;

//using operator

//Since I didn't write this it was giving me an error. class minute needs sec's object

//program doesn't work if I forward declare a class.
class minute
{

public:
    int min;

    minute() {}

    void display()
    {
        cout << "Time in min: " << min << endl;
    }
    int returnmin()
    {
        return min;
    }
};

class sec
{
    int secs = 60; //hardcoding for testing.

public:
    operator minute()
    {
        minute m;
        m.min = secs / 60;
        return m;
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
