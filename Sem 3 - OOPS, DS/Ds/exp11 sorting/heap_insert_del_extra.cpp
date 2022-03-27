#include "iostream"
using namespace std;
#define MAX 100

void heapify_delroot(int heap[], int i, int size)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;
    
    if (largest != i)
    {
        swap(heap[largest], heap[i]);
        heapify_delroot(heap, largest, size);
    }
    
}

void del(int heap[], int &size)
{
    heap[0] = heap[size - 1];
    size--;
    heapify_delroot(heap, 0, size);
}

void heapify_insert(int heap[], int size, int i)
{
    int parent = (i - 1) / 2;
    if(heap[parent] < heap[i])
    {
        swap(heap[i], heap[parent]);
        heapify_insert(heap, size, parent);
    }
    
}

void insert(int heap[], int &size, int key)
{
    heap[size] = key;
    size++;
    heapify_insert(heap, size, size - 1);
}

int main()
{
    int heap [MAX] = {10, 5, 3, 2, 4};
    int size = 5;
    insert(heap, size, 50);

    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    
    cout << endl;
    del(heap, size);
    del(heap, size);
    del(heap, size);
    del(heap, size);

    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }

}


// In heap sort no insertion is happening