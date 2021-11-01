#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char *pop();
char prefix[MAX];
char stack[MAX][MAX];
void push(char *str);
int isempty();
int whitespace(char symbol);
void prefixtopostfix();
int top;

int main()
{
    top = -1;
    printf("Enter Prefix Expression : ");
    gets(prefix);
    prefixtopostfix();
}

void prefixtopostfix()
{
    int i;
    char operand1[MAX], operand2[MAX];
    char symbol;
    char temp[2];
    char strin[MAX];
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        symbol = prefix[i];
        temp[0] = symbol;
        temp[1] = '\0';

        if (!whitespace(symbol))
        {
            switch (symbol)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                strcpy(operand1, pop());
                strcpy(operand2, pop());
                strcpy(strin, operand1);
                strcat(strin, operand2);
                strcat(strin, temp);
                push(strin);
                break;
            default:
                push(temp);
            }
        }
    }
    printf("\nPostfix Expression :: ");
    puts(stack[0]);
}

void push(char *str)
{
    if (top > MAX)
    {
        printf("\nStack overflow\n");
        exit(1);
    }
    else
    {
        top = top + 1;
        strcpy(stack[top], str);
    }
}

char *pop()
{
    if (top == -1)
    {
        printf("\nStack underflow \n");
        exit(2);
    }
    else
        return (stack[top--]);
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int whitespace(char symbol)
{
    if (symbol == BLANK || symbol == TAB || symbol == '\0')
        return 1;
    else
        return 0;
}