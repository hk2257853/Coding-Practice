#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

void insert();
void delete ();
void Displayfront();
void Display();

int isfull();
int isempty();

int isempty()
{
	if (front > rear - 1)
	{
		return 1;
	}
	return 0;
}

int isfull()
{
	if (rear > MAX - 2)
	{
		return 1;
	}
	return 0;
}

void Display()
{
	printf("The elements are: ");
	for (int i = front + 1; i <= rear; i++)
	{
		printf("%d ", queue[i]);
	}
}

void Displayfront()
{
	printf("Front: %d", queue[front + 1]);
}

void delete ()
{

	if (!isempty())
	{
		front++;
		queue[front] = 0;
	}
	else
	{
		printf("Queue is empty");
	}
}

void insert()
{

	if (!isfull())
	{
		rear++;
		printf("Enter data: ");
		scanf("%d", &queue[rear]);
	}
	else
	{
		printf("Queue is full");
	}
}

int main()
{
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
			insert();
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
