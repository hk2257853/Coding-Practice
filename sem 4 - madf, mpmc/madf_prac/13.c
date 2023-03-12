#include "stdio.h" 
 
// just do this n go
// if comes... use my brain n try to output the answer array... (I can just put in an array, if back tracked pop)

void subsetsum_Backtracking(int Set[] , int pos, int sum, int tmpsum, int size, int *found)
{
    if (sum == tmpsum)
        *found = 1;
        // generate nodes along the breadth
    for (int i = pos; i < size; i++) // can't digest this part... just rem... check later
    {
     if (tmpsum + Set[i] <= sum)
       {
          tmpsum += Set[i];   
          // consider next level node (along depth)
          subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
          tmpsum -= Set[i];
       }
    }
}

int main()
{
    int arr[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int s = 53, f = 0;

    subsetsum_Backtracking(arr, 0, s, 0, 8, &f);

    printf("%d", f);

}