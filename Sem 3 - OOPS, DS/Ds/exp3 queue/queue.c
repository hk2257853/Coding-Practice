#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

void insert(int x);
void delete ();
void Displayfront();
void Display();

void Display()
{
	printf("The elements are: ");
	for (int i = front; i <= rear; i++)
	{
		printf("%d ", queue[i]);
	}
}

void Displayfront()
{
	printf("Front: %d", queue[front]);
}

void delete ()
{
	if (front > rear || front == -1)
	{
		printf("Queue is empty");
	}
	else
	{
		front++;
	}
}

void insert(int x)
{
	if (rear == -1 && front == -1)
	{
		rear = 0, front = 0;
		queue[rear] = x;
	}
	else if (rear < MAX - 1)
	{
		rear++;
		queue[rear] = x;
	}
	else
	{
		printf("Queue is full");
	}
}

int main()
{
	int x;
	while (1)
	{
		printf("1 Insert\n");
		printf("2 Delete\n");
		printf("3 Display front\n");
		printf("4 Display\n");
		printf("Enter from option\n");

		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("Enter data: ");
			scanf("%d", &x);
			insert(x);
			break;
		case 2:
			delete ();
			break;
		case 3:
			Displayfront();
			break;
		case 4:
			Display();
			break;

		default:
			break;
		}
		printf("\n\n");
	}
}
