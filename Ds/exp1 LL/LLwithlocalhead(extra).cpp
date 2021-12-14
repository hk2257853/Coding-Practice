#include "iostream"
using namespace std;

class Node
{

public:
    int data;

    Node *next;
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

// Driver code

int main()
{

    Node *head = NULL;

    Node *second = NULL;

    Node *third = NULL;

    // allocate 3 nodes in the heap. Thus bigger scope
    head = new Node();
    second = new Node();
    third = new Node();
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printList(head); // we r passing pointer here. this pointer points to the list.
    // Why did tr ask to return pointer in class(for add at begining)?
    // Unless we r assingning it to some other thing, what's the use?

    return 0;
}