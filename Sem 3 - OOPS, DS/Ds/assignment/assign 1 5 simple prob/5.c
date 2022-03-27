#include <stdio.h>

struct ShopingList
{
    char item[50];
    int Price;
} s[2];

int main()
{
    for (int i = 0; i < 2; i++)
    {
        printf("Enter Item:\n");
        scanf("%s", &s[i].item);
        printf("Enter Price:\n");
        scanf("%d", &s[i].Price);
    }

    printf("\n\n");
    struct ShopingList *p2[2];
    for (int i = 0; i < 2; i++)
    {
        printf("Item %d:", i);
        p2[i] = &s[i];
        printf("%s\n", p2[i]->item);
        printf("%d\n", p2[i]->Price);
    }

    printf("Total Items: %d", sizeof(s) / sizeof(s[0]));
    return 0;
}