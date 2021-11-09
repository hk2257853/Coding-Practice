#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char stack[MAX];
int ind = -1;

void display();

char *pop()
{
    char *temp = &stack[ind];
    ind--;
    return temp;
}

void push(char *str)
{
    ind++;
    stack[ind] = str;
}

void input()
{
    char str[100] = "AB+";

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-')
        {
            // strcat(str[i], pop());
            // strcat(str[i], pop());
            printf("%c", str[i]);
            //            push(str[i]);
        }
        else
        {
            ind++;
            stack[ind] = str[i];
        }
    }

    display();
}

void display() // bottom to top
{
    for (int i = 0; i <= ind; i++)
    {
        printf("%c ", stack[i]);
    }
}

int main()
{
    input();
}