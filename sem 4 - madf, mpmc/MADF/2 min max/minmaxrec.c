#include<stdio.h>
#include<stdlib.h>
int count=0;
int space=0;
int a[30];
void MinMax(int i,int j,int *min,int *max)
{
	int mid=(i+j)/2,min1,max1;
	if(i==j)
	{
		*min=a[i];
		*max=a[i];
		return ;
	}
	else
	{
		if(i==(j-1))
		{
			if(a[i]<a[j])
			{
				*max=a[j];
				*min=a[i];
			}
			else
			{
				*max=a[i];
				*min=a[j];
			}
		}
	}
	MinMax(i,mid,min,max);
	MinMax(mid+1,j,&min1,&max1);
	if(*max<max1)
		*max=max1;
	if(*min>min1)
		*min=min1;
}
int main(){
	int n,min,max;
	space=space+3;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	int i,j;
	space=space+2;
	for(i=0;i<n;i++){
		count++; //for i
		count++; //for scanf
		scanf("%d",&a[i]);
	}count++; //for last instance of i
	space=space+n;
	i=0; space=space+1;
	j=(n-1); space=space+1;
	MinMax(i,j,&min,&max);
	printf("\nMin = %d",min);
	printf("\nMax = %d",max);
	printf("\nCount = %d",count);
	printf("\nSpace(for main) = %d",space);
	return 0;
}
