#include "iostream"
using namespace std;

int getnumlen(int num)
{
    if (num == 0) return 1;
    int count = 0;
    while (num != 0)
    {
        num = num /10;
        count++;
    }
    return count;
}

int main()
{
    int num;
    cin >> num;
    if (num < 10)
    {
        cout << num << endl;
    }

    int y = getnumlen(num);
    while (y > 1)
    {
        int sum = 0;
        for (int i = 0; i < y; i++)
        {
            int x = num % 10;
            num = num / 10;
            sum += x;
        }
        num = sum;
        y = getnumlen(num);
        cout << num << endl;
    }

}
