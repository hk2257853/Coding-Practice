#include <stdio.h>

int n = 5, profit[5], weight[5];

// I other code he made a copy of the original... not req
void sort(int arr1[], int arr2[]) // bubble sort
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr1[j] > arr1[j + 1]) 
            {
                swap(arr1[j], arr1[j + 1]);
                swap(arr2[j], arr2[j + 1]);
            }
        }
    }
    // how to adjust weights/profits while sort one of the quantities?
    // -> sort wrt profit, swap weight as well
    // vector pair would have been best for this!
}

void maxprofit()
{
    

}

int main()
{
    int choice;    

    while (1)
    {
        printf("1 Max profit\n");
        printf("2 min weight\n");
        printf("3 Max p/w ratio\n");                

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            maxprofit();
            break;
        case 2:
            
            break;
        case 3:
            
            break;        
        }
    }
    

    return 0;
}