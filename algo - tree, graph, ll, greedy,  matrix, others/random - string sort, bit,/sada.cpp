#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
    /* data */
};

class Solution
{
public:
    Node *addOne(Node *head)
    {
        int num = 0;
        struct Node *temp = head;
        while (temp != NULL)
        {
            num = num * 10 + temp->data;
            temp = temp->next;
        }

        num++;

        int remain;

        struct Node *newhead = new Node(NULL);
        newhead = NULL;

        while (num != 0)
        {
            struct Node *newnode = new Node(newnode->data = num % 10);

            num = num / 10;

            if (newhead == NULL)
            {
                newhead = newnode;
                newnode->next = NULL;
            }
            else // add at begining
            {
                newnode->next = newhead;
                newhead = newnode;
            }
        }

        return newhead;
    }
};

int main()
{
}