/* DMA for array of structure variables */
#include <stdio.h>
#include <stdlib.h>
struct course
{
  int marks;
  char subject[30];
};

int main()
{
  struct course *ptr;
  int n;
  printf("\nEnter the number of records: ");
  scanf("%d", &n);

  // Memory allocation for no of Records structure type(course)
  ptr = (struct course *)malloc(n * sizeof(struct course));

  for (int i = 0; i < n; ++i)
  {
    printf("\nEnter subject and marks:\n");
    //scanf("%s %d", &(ptr + i)->subject, &(ptr + i)->marks);
    scanf("%s %d", &ptr[i].subject, &ptr[i].marks);
  }

  printf("\nDisplaying Information:\n\n");
  for (int i = 0; i < n; ++i)
  {
    printf("%s\t%d\n", ptr[i].subject, ptr[i].marks);
    //printf("%s\t%d\n", (ptr + i)->subject, (ptr + i)->marks);
  }

  free(ptr);

  return 0;
}
