#include <stdio.h>

#define max 4
int queue[max];
int front = -1;
int rear = -1;

void Displayfront()
{
    printf("Front: %d", queue[front]);
}

void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front) // f in front of r
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue empty\n");
    }
    else if (front == rear)
    {               // My way: after deletion checking if f is in front of r and then send to -1. But that will be extra code... this is simple n good
        front = -1; // I can do withot sending to -1 too but this way checking for empty condition becomes much simpler
        rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements are: ");
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % max;
        }
    }
}
int main()
{
    int choice, x;

    while (1)
    {
        printf("1 Insert\n");
        printf("2 Delete\n");
        printf("3 Display front\n");
        printf("4 Display\n");
        printf("Enter from option\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Displayfront();
            break;
        case 4:
            display();
        }
        printf("\n");
    }
    return 0;
}