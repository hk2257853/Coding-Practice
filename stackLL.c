#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Start1;
struct Node *Start2;

void push();
void pop();
void display();
int isempty();
void displaytop();
void reverse();

void display2()
{

	int count = 0;
    struct Node *ptr;
    ptr = Start2;
    printf("The elements are:\n");
    while (ptr != NULL) //ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        printf("%d ", ptr->data);
        //write(ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\nThe size of stack is:%d", count); //size of list
}

void reverse()
{
int count = 0;
//1st copy on 2nd linked list
Start2=Start1; 
//copy data in 1 reverse


}	

void displaytop()
{

int count = 0;
    struct Node *ptr;
    ptr = Start1;
    printf("The elements are:\n");
    while (ptr->next != NULL) 
    {     
        ptr = ptr->next;
        count++;
    }
    printf("\nThe top is:%d", ptr->data); //size of list
}


int isempty()
{
	if(Start1==NULL) return 1;
	else return 0;
}

void push()
{
	
struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:\n");
        scanf("%d", &NewNode->data);
	//if empty
    if (Start1 == NULL)
    {
        Start1 = NewNode;
        NewNode->next = NULL;
    }
    else
    {
        struct Node *temp;
        

        temp = Start1;
        while (temp->next != NULL)
        {
            temp = temp->next; //transverse to last node
        }
        //make current last node to point to newnode. Don't delete temp. I need it for next time I call this func.
        temp->next = NewNode;
        temp = NewNode;
        NewNode->next = NULL;
    }
}

void display()
{

	int count = 0;
    struct Node *ptr;
    ptr = Start1;
    printf("The elements are:\n");
    while (ptr != NULL) //ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        printf("%d ", ptr->data);
        //write(ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\nThe size of stack is:%d", count); //size of list
}

void pop()
{

	if(isempty()==1)
	{
	printf("Stack underflow\n");
	}
	else
	{
		struct Node *ptr, *prev;
	    ptr = Start1;
	    while (ptr->next != NULL)
	    {
		prev = ptr;
		ptr = ptr->next;
	    }
	    free(ptr);
	    prev->next = NULL;
	}
}
int main()
{
	while(1)
	{	int n;
	printf("1 push\n");
	printf("2 pop\n");
	printf("3 Display\n");
	printf("4 Display top\n");
	printf("5 Reverse\n");	
	printf("6 exit\n");
	printf("Enter from options:\n");	
	
	scanf("%d", &n);

	switch(n)
	{
	case 1:
	push();
	break;
	case 2:
	pop();
	break;
	case 3:
	display();
	break;
	case 4:
	displaytop();
	break;
	case 5:
	reverse();
	break;
	case 6:
	display2();
	break;

	default:
            printf("Invalid Input");
            break;
	}

	printf("\n\n");

	}

	return 0;
}
