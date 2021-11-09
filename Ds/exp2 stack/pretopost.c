#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char *pop();
char prefix[MAX];
char stack[MAX][MAX];
void push(char *str);
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
    printf("\nPostfix Expression :: ");
    puts(stack[0]);
}

void push(char *str)
{
    top = top + 1;
    strcpy(stack[top], str);
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
