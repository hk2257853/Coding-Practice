// heaps
#include "iostream"
#include "queue"
using namespace std;

int main()
{
    int arr[6] = {10, 2, 4, 8, 6, 9};
    priority_queue<int> pq;

    for (int i = 0; i < 6; i++)
        pq.push(arr[i]);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < 6; i++)
        minheap.push(arr[i]);

    while (!minheap.empty())
    {
        cout << minheap.top() << " ";
        minheap.pop();
    }

    return 0;
}
