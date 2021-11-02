#include <stdio.h>

#define max 6
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
    else if ((rear + 1) % max == front)
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
    if ((front == -1) && (rear == -1))
    {
        printf("Queue empty\n");
    }
    else if (front == rear)
    {
        front = -1;
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
        while (i <= rear)
        {
            printf("%d ", queue[i]);
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
    }
    return 0;
}