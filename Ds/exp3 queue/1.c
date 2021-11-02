#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert();
void delete ();
void Displayfront();
void Display();

void Displayfront()
{
    printf("The front element if: %d", front->data);
}

void display() // front to rear
{
    printf("The elements are: ");
    struct Node *temp;
    temp = front;
    while (temp != rear)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", rear->data);
}

void delete ()
{
    if (front != rear && front != NULL)
    {
        struct Node *temp;
        temp = front;
        front = front->next;
        free(temp);
        rear->next = front;
    }
    else if (front == rear)
    {
        struct Node *temp;
        temp = front;
        rear = NULL;
        front = NULL;
        free(temp);
    }
    else if (rear == NULL)
    {
        printf("queue is empty");
    }
}

void insert()
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    NewNode->data = 5;
    if (rear == NULL)
    {
        rear = NewNode;
        front = NewNode;
        NewNode->next = front;
    }
    else
    {
        rear->next = NewNode;
        rear = NewNode;
        NewNode->next = front;
    }
}

int main()
{
    // while (1)

    printf("1 Insert\n");
    printf("2 Delete\n");
    printf("3 Display front\n");
    printf("4 Display\n");
    printf("Enter from option\n");
    insert();
    insert();
    insert();
    insert();

    delete ();
    delete ();
    delete ();
    delete ();
    delete ();
    delete ();
    delete ();

    int n;
    // scanf("%d", &n);
    switch (n)
    {
    case 1:
        insert();
        break;
    case 2:
        delete ();
        break;
    case 3:
        Displayfront();
        break;
    case 4:
        display();
        break;

    default:
        break;
    }
    printf("\n\n");
}
