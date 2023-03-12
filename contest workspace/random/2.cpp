#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

// I assumed "-"1-1+1  the 1st - is allowed
// too bored to do now

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int N, X;
        cin >> N >> X;

        if (X > N + 1 || X < -(N + 1) || ((N + 1) % 2 && X == 0))
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            int i = 0;
            if (X < 0)
            {
                while (i > X)
                {
                    cout << "-";
                    i--;
                }

                while (i > -(N + 1))
                {
                    cout << "*";
                    i--;
                }
            }
            else if (X > 0)
            {
                while (i < X - 1)
                {
                    cout << "+";
                    i++;
                }

                while (i < N)
                {
                    cout << "*";
                    i++;
                }
            }
            else
            {
                while (i <= N / 2)
                {
                    cout << "+";
                    i++;
                }
                while (i <= N)
                {
                    cout << "-";
                    i++;
                }
            }
        }

        cout << endl;
    }
    return 0;
}
