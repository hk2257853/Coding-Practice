//Reading from a console.

#include <stdio.h>

void read();
void write();

FILE *fp;
char location[100] = "D://data.txt", ch;
char text[100] = "Input output in file in c\n";

int main()
{
    write();

    read();
}

void read()
{
    //open the file. If doesn't exist it will create one.
    fp = fopen(location, "r"); //r for read mode. w for write mode

    //priting the file content in console
    do
    {
        ch = fgetc(fp);
        putchar(ch);
    } while (ch != EOF);

    //closes the file
    fclose(fp);
}

void write()
{
    //open the file. If doesn't exist it will create one.
    fp = fopen(location, "w"); //r for read mode. w for write mode

    //writing in file
    fprintf(fp, text);

    //closes the file
    fclose(fp);
}