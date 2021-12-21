#include <iostream>
using namespace std;

template <class T> // Should I take parametarised here?
class vector
{
    T *v;
    int size;

public:
    vector()
    {
        size = 0;
        v = new T[size + 1];
    }
    vector(int n)
    {
        size = n;
        v = new T[size + 1]; // so we make a array using dma here. Vector is dynamic array
    }

    void get_elements()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> v[i];
        }
    }

    void modifybyindex()
    {
        int ind;
        cout << "Enter index to modify: ";
        cin >> ind;
        cout << "\nEnter value: ";
        cin >> v[ind];
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> v1;
    int n;

    cout << "Enter total elements: ";
    cin >> n;
    v1 = (n);
    cout << "Enter elements:" << endl;
    v1.get_elements();
    v1.display();
    v1.modifybyindex();
    v1.display();

    return 0;
}
