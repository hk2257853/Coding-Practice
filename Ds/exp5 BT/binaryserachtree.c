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

// void add_node(int n);
// void preorder(struct Node *node);
// void inorder(struct Node *node);
// void postorder(struct Node *node);
// void search();
// void deletenode(struct Node *root, int num);
// void printlevel(struct Node *node, int lvl);
// void deletenode(struct Node *root, int num);
// struct Node *delete_queue();
// void levelorder();
// void add_node(int n);
// int height();
// void printallwidth();
// int printwidth(struct Node *node, int lvl);
// int maxnum(int num1, int num2);

int maxnum(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    int left = height(node->left);
    int right = height(node->right);

    return 1 + maxnum(left, right);
}

int printwidth(struct Node *node, int lvl)
{
    if (node == NULL)
        return 0;
    else if (lvl == 0)
    {
        return 1;
    }
    int left = printwidth(node->left, lvl - 1);
    int right = printwidth(node->right, lvl - 1);

    return left + right;
}

void printallwidth()
{
    int treeheight = height(root);
    for (int i = 0; i < treeheight; i++)
    {
        printf("Level %d Width: ", i);
        printf("%d\n", printwidth(root, i));
    }
}

void printlevel(struct Node *node, int lvl)
{
    if (node == NULL)
        return;
    else if (lvl == 0) // Base case: tree has only level 1 (my level starts from 0)
        printf("%d ", node->data);

    printlevel(node->left, lvl - 1); // if I need to print 5 then I need 4
    printlevel(node->right, lvl - 1);
}

// edge cases (wrt root) remaining
void deletenode(struct Node *node, int num)
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
        else
            prev->right = NULL;
        free(ptr);
    }
    else if (ptr->left == NULL && ptr->right != NULL) // has one child
    {
        if (ptr == root) // root is to be delted
        {
            root = root->right;
            free(ptr);
            return;
        }

        if (prev->left == ptr)
            prev->left = ptr->right;
        if (prev->right == ptr)
            prev->right = ptr->right;
        free(ptr);
    }
    else if (ptr->right == NULL && ptr->left != NULL)
    {
        if (ptr == root) // root is to be delted
        {
            root = ptr->left;
            free(ptr);
            return;
        }

        if (prev->left == ptr)
            prev->left = ptr->left;
        if (prev->right == ptr)
            prev->right = ptr->left;
        free(ptr);
    }
    else if (ptr->left != NULL && ptr->right != NULL) // 2 child
    {
        struct Node *minptr = ptr->right;
        while (minptr->left != NULL)
        {
            minptr = minptr->left;
        }

        int minptrdata = minptr->data; // by doing this little change it started working!
        deletenode(root, minptrdata);  // Earlier I 1st exchanged data n then deleted due
        ptr->data = minptrdata;        // to which the nos were no more in that sorted way
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

void insert_queue(struct Node *x)
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

void levelorder()
{
    insert_queue(root);

    while (front <= rear)
    {
        struct Node *temp = delete_queue();
        printf("%d ", temp->data);
        if (temp->left)
            insert_queue(temp->left);
        if (temp->right)
            insert_queue(temp->right);
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

int main()
{

    while (1)
    {
        printf("0 Add elements\n");
        printf("1 Add element\n");
        printf("2 delete element\n");
        printf("3 preorder traversal\n");
        printf("4 inorder traversal\n");
        printf("5 postorder traversal\n");
        printf("6 search\n");
        printf("7 printlevel\n");
        printf("8 levelorder\n");
        printf("9 print width\n");
        printf("Enter from options\n");
        int n;
        scanf("%d", &n);
        int x, Telements;

        switch (n)
        {
        case 0:
            printf("Total elements: ");
            scanf("%d", &Telements);

            for (int i = 0; i < Telements; i++)
            {
                scanf("%d", &x);
                add_node(x);
            }
            break;
        case 1:
            scanf("%d", &x);
            add_node(x);
            break;
        case 2:
            scanf("%d", &x);
            deletenode(root, x);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            search();
            break;
        case 7:
            printf("Enter level to print: ");
            int lvl;
            scanf("%d", &lvl);
            printlevel(root, lvl);
            break;
        case 8:
            levelorder();
            break;
        case 9:
            printallwidth();
            break;
        }

        printf("\n\n");
    }
}
