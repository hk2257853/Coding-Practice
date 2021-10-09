#include <stdio.h>

struct bank
{
    int id, balance, transaction;
    char name[30];
};

int main()
{
    printf("%d", sizeof(struct bank));
    struct bank *u = NULL;
    int TUsr;
    printf("Enter Total users:\n");
    scanf("%d", &TUsr);
    u = (struct bank *)malloc(TUsr * sizeof(struct bank));
    printf("%d", u);
}