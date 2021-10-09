#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int ind=1; //assuming index starts from 1
int ind2=MAX;
int stack[MAX];
int stack2[MAX];

void push();
void pop();
void display();
int isfull();
int isempty();
void displaytop();
void reverse();

void reverse()
{
	for(int i=1; i<ind;i++)
	{	
	stack2[ind2-1]=stack[i]; //copying in reverse in other stack.
	ind2--;
	}
	for(int i=1; i<ind;i++)	//copying in the main stack.
	{	
	stack[i]=stack2[i];
	}
}


void displaytop()
{
	printf("The top element is: %d \n", stack[ind]);
	
}

int isempty()
{
	if(ind<=1) return 1;
	else return 0;
}

int isfull()
{
	if(ind>=MAX) return 1;
	else return 0;
}

void push()
{	
	//check if full
	if(isfull()==1)
{
printf("Stack overflow\n");
}
	else
{
	printf("Enter the number\n");
	scanf("%d",&stack[ind]);
	ind++;
}
}

void display()
{
	for(int i=1; i<ind;i++)
	{
	printf("%d ",stack[i]);
	}
}

void pop()
{
	if(isempty()==1)
{
printf("Stack underflow\n");
}
	else
{
		
	stack[ind]=0;
	ind--;
}
}

int main()
{
	while(1)
	{	int n;
	printf("1 Add element\n");
	printf("2 Remove element\n");
	printf("3 Display\n");
	printf("4 Display top element\n");
	printf("5 Reverse elements\n");	
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
	exit(0);
	break;

	default:
            printf("Invalid Input");
            break;
	}

	printf("\n\n");

	}

	return 0;
}
