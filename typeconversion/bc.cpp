#include "iostream"
using namespace std;

class minute
{
    int min;

public:
    minute() {}
    minute(int x)
    {
        min = x / 60;
    }

    void display()
    {
        cout << "Time in min: " << min << endl;
    }
};

int main()
{
    minute time;
    int timesec = 60;
    time = timesec;
    time.display();
    return 0;
}
