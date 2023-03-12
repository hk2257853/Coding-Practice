#include<stdio.h>
int count=0;
int main()
{
    int A[2][2],B[2][2],C[2][2],i,j;
    printf("Enter the elements of matrix A :\n");count++;
    for(i=0;i<2;i++)
    {
        count++;
        for(j=0;j<2;j++)
        {
            count++;
            scanf("%d",&A[i][j]);count++;
        }count++;
    }count++;
    printf("Enter the elements of matrix B :\n");count++;
    for(i=0;i<2;i++)
    {
        count++;
        for(j=0;j<2;j++)
        {
            count++;
            scanf("%d",&B[i][j]);count++;
        }count++;
    }count++;

    int P,Q,R,S,T,U,V;
    P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);count++;
    Q=(A[1][0]+A[1][1])*B[0][0];count++;
    R=A[0][0]*(B[0][1]-B[1][1]);count++;
    S=A[1][1]*(B[1][0]-B[0][0]);count++;
    T=(A[0][0]+A[0][1])*B[1][1];count++;
    U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);count++;
    V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);count++;

    C[0][0]=P+S-T+V;count++;
    C[0][1]=R+T;count++;
    C[1][0]=Q+S;count++;
    C[1][1]=P+R-Q+U;count++;

    printf("\n\nThe elements of matrix C : \n");count++;
    for(i=0;i<2;i++)
    {
        count++;
        for(j=0;j<2;j++)
        {
            count++;
            printf("%4d",C[i][j]);count++;
        }
        printf("\n");
    }
    printf("\nStep Count = %d\n",count);
    return 0;
}