#include <stdio.h>
#include <stdlib.h>
// TODO: level order n search, delete
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

void add_node(int n);

void deletenode()
{
printf("Enter Node to delte: ");
int num;
scanf("%d", &num);

//Go at required location
    struct Node *ptr = root, *prev;
    while (ptr != NULL)
    {
        if (num==ptr->data)
        {
        break;
        }
        prev=ptr;
        if (num > ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }

    if(ptr->left==NULL && ptr->right==NULL)
    {
    free(ptr);
    }

}

void levelorder()
{


}

void search()
{
int num;
printf("Enter Number: ");
scanf("%d", &num);

struct Node *ptr=root;
int flag=0;

    while (ptr != NULL && flag!=1)
    {

        if (num==ptr->data)
        {
        printf("Element is present\n");
        flag=1;
        break;
        }

        if (num > ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }

    if(flag==0) printf("not present\n");
}

void preorder(struct Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(struct Node *node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void add_node(int n)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = n;

    if (root == NULL)
    {
        root = newnode;
        return;
    }

    struct Node *ptr = root, *prev;
    while (ptr != NULL)
    {
        prev = ptr;
        if (n > ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }

    if (n > prev->data)
    {
        prev->right = newnode;
    }
    else
    {
        prev->left = newnode;
    }
}

int main()
{
    int arry[] = {5, 8, 3,10,2,11,16};

    for (int i = 0; i < sizeof(arry) / sizeof(arry[0]); i++)
    {
        add_node(arry[i]);
    }

    printf("preorder trasversal: ");
    preorder(root);

    printf("\ninorder trasversal: ");
    inorder(root);

    printf("\npostorder trasversal: ");
    postorder(root);

    while(1)
    {
    printf("\n");
    search();
    }
}
