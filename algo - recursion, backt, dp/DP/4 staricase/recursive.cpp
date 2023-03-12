#include "iostream"
using namespace std;

// its actually fibinacii!!!!
// it was looking a little familiar

int getallpossibilities(int n)
{
    if(n <= 1) return n; // if(n <= 0) return 0 doesn't work
    
    // 2 possibilities I can take 1, I can take 2
    return getallpossibilities(n - 1) +  getallpossibilities(n - 2);

}

int main()
{
    int n = 4;
    cout << getallpossibilities(n + 1) << endl;
}