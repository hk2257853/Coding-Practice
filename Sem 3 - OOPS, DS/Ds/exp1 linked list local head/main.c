//Experiment 1a Single Linked List. Name:Farhan Bukhari Roll No:201105017 Comp A
#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *link;	
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
void filewrite(struct node *start);
int main()
{
	struct node *start=NULL;
	int choice,data,item,pos;
	while(1)
	{
		printf("1.Create list\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add to empty/Add to beginning\n");
		printf("6.Add at the end\n");
		printf("7.Add after the node\n");
		printf("8.Add before the node\n");
		printf("9.Add at position\n");
		printf("10.Reverse the linked list\n");
		printf("11.Write the LL to the file and exit\n");
		printf("12.Exit\n\n");
		printf("Enter your choice:");
		scanf("%d",&choice);                            
			       
		switch(choice){
		case 1:
			start=create_list(start);
			break;
		case 2:
			display(start);
			break;
		case 3:
			count(start);
			break;
		case 4:
			printf("Enter the element to be searched.");
			scanf("%d",&data);
			search(start,data);
			break;
		case 5:
			printf("Enter the element to be inserted:");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;
		case 6:
			printf("Enter the element to be inserted:");
			scanf("%d",&data);
			start=addatend(start,data);
			break;
		case 7:
			break;
		case 8:
			printf("Enter the element to be inserted:");
			scanf("%d",&data);
			printf("Enter the element before which to insert:");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;
		case 9:
			printf("Enter the element to be inserted:");
			scanf("%d",&data);
			printf("Enter the position at which to insert:");
			scanf("%d",&pos);
			start=addatpos(start,data,item);
			break;
		case 10:
			start=reverse(start);
			break;
		case 11:
			filewrite(start);
			break;
		case 12:
			exit(1);
		
		default:
			printf("Wrong choice.\n");
		}
	}
	return 0;
}
struct node *create_list(struct node *start)
{
int i,n,data;
printf("Enter the number of nodes:");
scanf("%d",&n);
start=NULL;
	if(n==0)
		return start;
printf("Enter the element to be inserted:");
scanf("%d",&data);
start=addatbeg(start,data);
	for(i=2;i<=n;i++) //0 is start,1 is addatbeg, 2 onwards start.
	{
		printf("Enter the element to be inserted:");
		scanf("%d",&data);
		start=addatend(start,data);	
	}
return start;	
}

struct node *addatend(struct node *start,int data)
{
struct node *p,*tmp;
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;
p=start;
	while(p->link!=NULL)
	{
	p=p->link;
	}	
p->link=tmp;
tmp->link=NULL;
return start;
}

struct node *addatbeg(struct node *start,int data)
{
struct node *tmp;
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;
tmp->link=start;
start=tmp;
return start;	
}

void display(struct node *start)
{
struct node *p;
if(start==NULL){
	printf("List is empty\n");
	return;
}
p=start;
printf("List is:\n");
while(p!=NULL)
{
printf("%d ",p->info);
p=p->link;	
}
printf("\n\n");
}

void count(struct node *start)
{
struct node *p;
int cnt=0;
p=start;
while(p!=NULL)
	{
	p=p->link;
	cnt++;	
	}	
printf("Number of elements are %d\n",cnt);
}

void search(struct node *start,int item)
{
struct node *p=start;
int pos=1;
while(p!=NULL)
	{
		if(p->info==item)
		{
		printf("Item %d found at position %d\n",item,pos);
		return;	
		}
	p=p->link;
	pos++;	
	}
printf("Item %d not found in list\n",item);	
}

struct node *addbefore(struct node *start,int data,int item)
{
struct node *p,*tmp;
if(start==NULL)
{
printf("List is empty.");
return start;	
}
if(start->info==item)
{
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;
tmp->link=start;
start=tmp;
return start;
}
p=start;
while(p->link!=NULL)
{
	if(p->link->info==item)
	{
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=p->link;
	p->link=tmp;
	return start;	
	}
p=p->link;	
}
printf("Item %d not found in the list.\n",item);
}

struct node *addatpos(struct node *start,int data,int pos)
{
struct node *tmp,*p;
int i;
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;
	if(pos==1)
	{
	tmp->link=start;
	start=tmp;
	return start;
	}
p=start;
for(i=1;i<pos-1&&p!=NULL;i++)
p=p->link;
if(p==NULL)
printf("There are less than %d elements.\n",pos);
else{
tmp->link=p->link;
p->link=tmp;	
}
return start;	
}

struct node *del(struct node *start,int data)
{
struct node *tmp,*p;
if(start==NULL)
{
printf("List is empty.\n");
return start;	
}
if(start->info==data)
{
tmp=start;
start=start->link;
free(tmp);
return start;	
}
p=start;
while(p->link!=NULL)
	{
	if(p->link->info==data)
	{
	tmp=p->link;
	p->link=tmp->link;
	free(tmp);
	return start;	
	}
	p=p->link;
	}	
printf("Element %d not found\n",data);
return start;	
}

struct node *reverse(struct node *start)
{
struct node *prev,*ptr,*next;
prev=NULL;
ptr=start;
while(ptr!=NULL)
	{
	next=ptr->link;
	ptr->link=prev;
	prev=ptr;
	ptr=next;
	}
start=prev;
return start;		
}

void filewrite(struct node *start)
{
FILE *fp;
fp=fopen("LinkedList.txt","w");
struct node *p;
if(start==NULL)
{
fprintf(fp,"The linked list is empty!");
return;	
}
p=start;
fprintf(fp,"The linked list is:\n");
while(p->link!=NULL)
{
fprintf(fp,"%d ",p->info);
p=p->link;	
}
fprintf(fp,"%d",p->info);
exit(1);
}


