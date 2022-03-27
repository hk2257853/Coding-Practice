#include "iostream"
using namespace std;
#include <queue>
// one of the ways: make array of 10 LL queues

int GetDigitatPosition(int number, int position)
{
    int digit;
    while (position > 0)
    {
        digit = number % 10;
        number = number / 10;
        position--;
    }
    return digit;
}

void RadixSort(int elements[], int count)
{

    /* 10 queues for sorting digits */
    queue<int> *q[10];
    int i, j, k, digits, max = -2147483648;

    /* Determine max number */
    for (i = 0; i < count; i++)
    {

        if (elements[i] > max)
        {
            max = elements[i];
        }
    }
    i = 0;
    /* Determine max decimal digits */
    while (max)
    {
        max = max / 10;
        i++;
    }
    digits = i;

    /* Take elements from digit = 0 to max digit and sort */
    for (i = 0; i < digits; i++)
    {
        /* Initialize queue */
        for (int j = 0; j < 10; j++)
        {
            q[j] = new queue<int>;
        }
        /* Populate the queue(s) based on digit */
        for (k = 0; k < count; k++)
        {
            /* get the digit */
            int digit = GetDigitatPosition(elements[k], i + 1);

            /* enqueue at the rare of digit's queue */
            q[digit]->push(elements[k]);
        }
        /* Dequeue individual queues to elements array */
        k = 0;
        for (j = 0; j < 10; j++)
        {
            while (!q[j]->empty())
            {
                /* dequeue from front */
                elements[k] = q[j]->front();
                q[j]->pop();
                k++;
            }
        }
        /* Cleanup the queues */
        for (j = 0; j < 10; j++)
        {
            delete q[j];
        }
    }
}

int main()
{
    int n = 6;
    int arr[n] = {18, 8, 9, 1, 2, 20};

    RadixSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Done";
}