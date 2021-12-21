#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int data;
	struct Node *next, *prev;
};

struct Node *start = NULL;

void add_beg(int x);
void ispalindrome();
void Enterstring();

int main()
{
    Enterstring();
}

void Enterstring()
{
	char str[100];
	printf("Enter string: ");
	scanf("%s", str);//I should not put & here
	int n=strlen(str);
	for (int i = 0; i < n; i++)
	{
		add_beg(str[i]);
	}

    ispalindrome();

}

void add_beg(int x)
{
	struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
	NewNode->data=x;

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

void ispalindrome()
{
    struct Node *beg=start;
    struct Node *end=start;

    while(end->next)//send at end
    {
    end=end->next;
    }
    int flag=1;
    while(end != beg)
    {
        if(end->data!=beg->data)
        {
        flag=0;
        break;
        }
        beg=beg->next;
        end=end->prev;
    }
    if(flag==1) printf("Its a palindrome");
    else printf("Its not a palindrome");

}
