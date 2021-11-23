#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node *queue[MAX];
int front = -1, rear = -1;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

void add_node(int n);
void preorder();

void deletenode(struct Node *root, int num)
{

    // Go at required location
    struct Node *ptr = root, *prev;
    while (ptr->data != num)
    {
        prev = ptr;
        if (num > ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }

    if (ptr->left == NULL && ptr->right == NULL) // if its a leaf node. Check if works for more than 3 element
    {
        if (prev->left == ptr)
            prev->left = NULL;
        if (prev->right == ptr)
            prev->right = NULL;
        free(ptr);
    }
    else if (ptr->left == NULL && ptr->right != NULL) // has one child
    {
        if (prev->left == ptr)
            prev->right = ptr->right;
        if (prev->right == ptr)
            prev->right = ptr->right;
        free(ptr);
    }
    else if (ptr->right == NULL && ptr->left != NULL)
    {
        if (prev->left == ptr)
            prev->left = ptr->left;
        if (prev->right == ptr)
            prev->left = ptr->left;
        free(ptr);
    }
    else if (ptr->left != NULL && ptr->right != NULL) // 2 child. Not working
    {
        struct Node *minptr = ptr->right;
        while (minptr->left != NULL)
        {
            minptr = minptr->left;
        }

        ptr->data = minptr->data;
        minptr->data = num;
        deletenode(minptr, num);
    }
}

struct Node *delete_queue()
{
    if (front > rear || front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        struct Node *temp = queue[front];
        front++;
        return temp;
    }
}
void search()
{
    int num;
    printf("Enter Number: ");
    scanf("%d", &num);

    struct Node *ptr = root;
    int flag = 0;

    while (ptr != NULL && flag != 1)
    {

        if (num == ptr->data)
        {
            printf("Element is present\n");
            flag = 1;
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

    if (flag == 0)
        printf("not present\n");
}

void insert(struct Node *x)
{
    if (rear == -1 && front == -1)
    {
        rear = 0, front = 0;
        queue[rear] = x;
    }
    else if (rear < MAX - 1)
    {
        rear++;
        queue[rear] = x;
    }
    else
    {
        printf("Queue is full");
    }
}

void levelorder()
{
    insert(root);

    while (front <= rear)
    {
        struct Node *temp = delete_queue();
        printf("%d ", temp->data);
        if (temp->left)
            insert(temp->left);
        if (temp->right)
            insert(temp->right);
    }
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
    int arry[] = {5, 3, 11};

    for (int i = 0; i < sizeof(arry) / sizeof(arry[0]); i++)
    {
        add_node(arry[i]);
    }
    // search();
    //  printf("preorder Transversal: ");
    preorder(root);
    printf("\nEnter Node to delete: ");
    int num;
    // scanf("%d", &num);
    deletenode(root, 5);
    preorder(root);

    // printf("\ninorder Transversal: ");
    // inorder(root);

    // printf("\npostorder Transversal: ");
    // postorder(root);

    // printf("\nLevelorder traversal: ");
    // levelorder();
}
