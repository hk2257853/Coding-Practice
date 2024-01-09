#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

void printans(char a[3])
{
    int arr[3] = {0, 0, 0};
    char ans = 'X';
    for (int i = 0; i < 3; i++)
    {
        if(a[i] == '?') continue;
        arr[a[i] - 'A']++;
    }
    if (arr[0] == 0)
        ans = 'A';
    else if (arr[1] == 0)
        ans = 'B';
    else if (arr[2] == 0)
        ans = 'C';
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char a[3];
        char ans = 'X';        

        for (int j = 0; j < 3; j++)
        {
            bool flag = false;
            for (int i = 0; i < 3; i++)
            {
                cin >> a[i];
                if (a[i] == '?')
                    flag = true;
            }

            if (flag)
            {
                printans(a);
            }
        }
    }
    return 0;
}