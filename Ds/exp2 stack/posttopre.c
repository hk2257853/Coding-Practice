#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char stack[30];
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
        char temp[2];
        temp[0] = str[i];
        temp[1] = '\0';
        if (str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-')
        {
            char operand1[MAX], operand2[MAX];
            strcpy(operand1, pop());
            strcpy(operand2, pop());
            strcat(operand1, operand2);
            strcat(operand1, str[i]);
            push(operand1);
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
        printf("%c", stack[i]);
    }
}

int main()
{
    input();
}