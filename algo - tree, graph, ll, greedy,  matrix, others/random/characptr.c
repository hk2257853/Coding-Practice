#include <stdio.h>

const char *myName()
{
    char *name = "Flavio";
    printf("%s", name);

    return name;
}

int main(void)
{
    myName();
}