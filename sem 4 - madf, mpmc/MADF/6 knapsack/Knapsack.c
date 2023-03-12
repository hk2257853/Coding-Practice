#include<stdio.h>
#include<string.h>
#define MAX 20
int wt[MAX],pr[MAX],n;

float maximum(float x, float y){
    if (x > y){
        return x;
    }
    return y;
}

void display(float X[])
{
    int i;
    printf("Choice of objects = (");
    for(i=0;i<n;i++)
    {
        if (i!=n-1)
            printf("%.2f,",X[i]);
        else
            printf("%.2f",X[i]);
    }   
    printf(")\n");
    
}

float findmaxprice(int weight[MAX],int price[MAX],int max_weight,int ch){
    int i,max;
    float profit = 0,X[MAX];
    
    for(i=0;i<n;i++){
    	wt[i] = weight[i];
    	pr[i] = price[i];
    	X[i] = 0.0;
	}
    
    while(max_weight > 0){
        max = pr[0];
        for(i=1;i<n;i++){
            if (pr[i] > max){
                max = pr[i];
            }
        }
        for(i=0;i<n;i++){
            if (pr[i] == max){
                break;
            }
        }
        max_weight = max_weight - wt[i];
        if (max_weight < 0){
            max_weight = max_weight + wt[i];
            break;
        }
        else{
            profit = (profit + pr[i])*1.0;
            X[i] = 1.0;
            wt[i] = 0;
            pr[i] = 0;
        }
    }
    if (max_weight != 0){
        X[i] = ((max_weight*1.0)/wt[i])*1.0;
    	float rem = (pr[i]*((max_weight*1.0)/wt[i])*1.0);
        profit = profit + rem;
    }
    if (ch == 0)
    	display(X);
    return profit;
}

float findleastweight(int weight[MAX],int price[MAX],int max_weight,int ch){
    float profit = 0,X[MAX];
    int i,leastweight;
    
    for(i=0;i<n;i++){
    	wt[i] = weight[i];
    	pr[i] = price[i];
    	X[i] = 0.0;
	}
	
    while(max_weight > 0){
        leastweight = 1000000;
        for(i=0;i<n;i++){
            if (leastweight > wt[i] && wt[i] != -1){
                leastweight = wt[i];
			}
        }
        for(i=0;i<n;i++){
            if (leastweight == wt[i]){
                break;
            }
        }
        max_weight = max_weight - wt[i];
        if (max_weight < 0){
            max_weight = max_weight + wt[i];
            break;
        }
        else{
            profit += pr[i];
            X[i] = 1.0;
            pr[i] = 0;
            wt[i] = -1;
        }
    }
    if (max_weight > 0)
    {
        profit = profit + pr[i]*((max_weight*1.0)/wt[i]);
        X[i] = ((max_weight*1.0)/wt[i])*1.0;
	}
	if (ch == 0)
    	display(X);
    return profit;
}

float finddecreasingorder(int weight[MAX],int price[MAX],int max_weight,int ch){
    float pbyw[MAX],X[MAX];
	int i;
    float profit = 0,max;

	for(i=0;i<n;i++){
    	wt[i] = weight[i];
    	pr[i] = price[i];
    	X[i] = 0.0;
    	pbyw[i] = (pr[i]*1.0)/wt[i];
	}

    while(max_weight > 0){
        max = pbyw[0];
        for(i=1;i<n;i++){
            if (pbyw[i] > max){
                max = pbyw[i];
            }
        }
        for(i=0;i<n;i++){
            if (pbyw[i] == max){
                break;
            }
        }
        max_weight = max_weight - wt[i]; 
        if (max_weight < 0){
            max_weight = max_weight + wt[i];
            break;
        }
        else{
            profit = profit + pr[i];
            X[i] = 1.0;
            pbyw[i] = 0;
        }
    }
    if (max_weight != 0){
        X[i] = ((max_weight*1.0)/wt[i]);
        profit = profit + pr[i]*((max_weight*1.0)/wt[i]);
    }
    if (ch == 0)
    	display(X);
    return profit;
}

int main()
{
    int i,max_weight,weight[MAX],price[MAX],choice;
    float maxprice,leastweight,decreasingorderofpbyw,maxprofit;
    char msg[50];

    printf("Enter the number of elements:");
    scanf("%d",&n);

    printf("Enter the value of m:");
	scanf("%d",&max_weight);

    for(i=0;i<n;i++){
        printf("Enter weight and price of the element %d:",i+1);
        scanf("%d%d",&weight[i],&price[i]);
    }
    
    printf("\n-------------------------------------------------------------\n");
    while(1)
    {
		printf("1. Maximum profit\n");
		printf("2. Minimum weight\n");
		printf("3. Decreasing order of Pi/Wi\n");
		printf("4. Find out the optimal solution\n");
		printf("5. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: maxprice = findmaxprice(weight,price,max_weight,0);
					printf("Profit = %.2f\n",maxprice);
					printf("\n-------------------------------------------------------------\n");
					break;
					
			case 2: leastweight = findleastweight(weight,price,max_weight,0);
    				printf("Profit = %.2f\n",leastweight);
    				printf("\n-------------------------------------------------------------\n");
					break;
					
			case 3: decreasingorderofpbyw = finddecreasingorder(weight,price,max_weight,0);
					printf("Profit = %.2f\n",decreasingorderofpbyw);
					printf("\n-------------------------------------------------------------\n");
					break;
					
			case 4:
					maxprice = findmaxprice(weight,price,max_weight,1);
					leastweight = findleastweight(weight,price,max_weight,1);
					decreasingorderofpbyw = finddecreasingorder(weight,price,max_weight,1);
					maxprofit = maximum(maxprice,leastweight);
    				maxprofit = maximum(maxprofit,decreasingorderofpbyw);

    				if (maxprofit == maxprice)
        				strcpy(msg,"maximum price of objects");
    				else if (maxprofit == leastweight)
        				strcpy(msg,"least weight of objects");
    				else if (maxprofit == decreasingorderofpbyw)
        				strcpy(msg,"decreasing order of Pi/Wi of objects");
    
    				printf("Maximum profit = %.2f which is obtained by taking %s\n",maxprofit,msg);
    				printf("\n-------------------------------------------------------------\n");
    				break;
    		
    		case 5: return 0;
    		default:printf("Invalid choice. Try again!!!\n");	
    				printf("\n-------------------------------------------------------------\n");
		}
	}
}
