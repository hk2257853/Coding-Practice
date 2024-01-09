#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include <math.h>

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int a, b;
        cin >> a >> b;
        bool flag = true;

        for (int i = a; i <= b; i++)
        {
            if (i % 2 == 0)
            {
                if (i / 2 == 1)
                    continue;
                cout << i / 2 << " " << i / 2 << endl;
                flag = false;
                break;
            }
        }

        if (a == b && a % 2 == 1)
        {
            // for this part chat gpt help me. prompt: 
            // Given an odd number like 15, split in 2 numbers such that gcd(n1,n2)!=1
            // this was really fun as its like pair programming

            for (int i = 2; i <= sqrt(a); ++i)
            {
                if (a % i == 0)
                {
                    cout << i << ' ' << a - i << endl;
                    flag = false;
                    break;
                }
            }
            // TC: O(sqrt(a))
        }

        if (flag)
            cout << "-1" << endl;
    }
    return 0;
}


// ACCEPTED!!!!