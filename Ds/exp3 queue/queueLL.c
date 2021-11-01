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
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void delete ()
{
	if (front != NULL)
	{
		struct Node *temp;
		temp = front;
		front = front->next;
		free(temp);
	}
	else
	{
		printf("Queue is empty");
	}
}

void insert()
{

	struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter data: ");
	NewNode->next = NULL;
	scanf("%d", &NewNode->data);
	if (rear == NULL)
	{
		rear = NewNode;
		front = NewNode;
	}
	else
	{
		rear->next = NewNode;
		rear = NewNode;
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
			display();
			break;

		default:
			break;
		}
		printf("\n\n");
	}
}
