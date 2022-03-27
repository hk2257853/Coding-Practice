#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next, *prev;
};

struct Node *start = NULL;

void createnode();
void createlist();
void displaylist();
void add_beg();
void add_end();
void add_after();
void add_before();
void deletenode();

int main()
{
	while (1)
	{
		int n;
		printf("1 Create linked list\n");
		printf("2 Display linked list\n");
		printf("3 Add at beginning\n");
		printf("4 Add at end\n");
		printf("5 Add after\n");
		printf("6 Add before\n");
		printf("7 delete\n");
		printf("Enter from options\n");

		scanf("%d", &n);

		switch (n)
		{
		case 1:
			createlist();
			break;
		case 2:
			displaylist();
			break;
		case 3:
			add_beg();
			break;
		case 4:
			add_end();
			break;
		case 5:
			add_after();
			break;
		case 6:
			add_before();
			break;
		case 7:
			deletenode();
			break;
		}

		printf("\n\n");
	}
}

/* struct Node* createnode()
{
	struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
printf("Enter data: ");
scanf("%d", &NewNode->data);
return NewNode;

}
*/
void createlist()
{
	int n;
	printf("Enter Total elements: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		add_end();
	}
}

void displaylist()
{
	printf("The elements are: ");
	struct Node *temp = start;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void add_beg()
{
	struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d", &NewNode->data);

	if (start == NULL)
	{
		start = NewNode;
		NewNode->prev = NULL;
		NewNode->next = NULL;
	}
	else
	{
		start->prev = NewNode;
		NewNode->prev = NULL;
		NewNode->next = start;
		start = NewNode;
	}
}

void add_end()
{

	if (start == NULL)
	{
		add_beg();
	}
	else
	{
		struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);

		struct Node *temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = NewNode;
		NewNode->prev = temp;
		NewNode->next = NULL;
	}
}

void add_after()
{
	int pos; // assuming position starts from 1
	printf("Enter position");
	scanf("%d", &pos);
	struct Node *temp = start;

	while (pos > 1)
	{
		temp = temp->next;
		pos--;
	}

	// if last
	if (temp->next == NULL)
	{
		add_end();
	}
	else
	{
		struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);

		struct Node *tempnxt = temp->next;
		NewNode->next = tempnxt;
		NewNode->prev = temp;
		temp->next = NewNode;
		tempnxt->prev = NewNode;
	}
}

void add_before()
{
	int pos; // assuming position starts from 1
	printf("Enter position");
	scanf("%d", &pos);
	struct Node *temp = start;

	while (pos > 2)
	{
		temp = temp->next;
		pos--;
	}

	// if pos is 1
	if (pos == 1)
	{
		add_beg();
	}
	else
	{
		struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);

		struct Node *tempnxt = temp->next;
		NewNode->next = tempnxt;
		NewNode->prev = temp;
		temp->next = NewNode;
		tempnxt->prev = NewNode;
	}
}

void deletenode()
{
	int pos;
	printf("Enter position: ");
	scanf("%d", &pos);

	struct Node *temp = start;

	if (pos == 1)
	{
		start = start->next;
		if (start != NULL)
		{
			start->prev = NULL;
		}
		free(temp);
	}
	else
	{
		while (pos > 1)
		{
			temp = temp->next;
			pos--;
		}

		temp->prev->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev;
		}
		free(temp);
	}
}
