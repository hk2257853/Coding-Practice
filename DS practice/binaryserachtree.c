#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int ind = -1;
struct Node *stack[MAX];

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

void add_node(int n);
void preorder();
void push();
struct Node *pop();
int isempty();

void nrec_postorder()
{
    struct Node *ptr = root;
    while (ptr != NULL || !isempty())
    {
        while (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->left;
        }
        if (stack[ind]->right)
        {
            ptr = stack[ind]->right;
        }
        else
        { // this part I need to get:(I understood 70% on my own but having a small issue)

            struct Node *temp = pop(); // like a do while loop..
            printf("%d ", temp->data);
            while (!isempty() && temp == stack[ind]->right)
            {
                temp = pop();
                printf("%d ", temp->data);
            }
        }
    }
}

// tr's code is not working. Ask someone/check on yt later.
// void nrec_postorder()
// {
//     struct Node *ptr = root, *q = root;
//     while (1)
//     {
//         while (ptr->left)
//         {
//             push(ptr);
//             ptr = ptr->left;
//         }

//         while (ptr->right != NULL || ptr->right == q)
//         {
//             printf("%c ", ptr->data);
//             q = ptr;
//             if (isempty())
//                 return;
//             ptr = pop();
//         }
//         push(ptr);
//         ptr = ptr->right;
//     }
// }

// understand this:
void nonrecur_inorder()
{
    struct Node *ptr = root;
    while (ptr != NULL || !isempty())
    {
        while (ptr)
        {
            push(ptr);
            ptr = ptr->left;
        }

        ptr = pop();
        printf("%d ", ptr->data);
        ptr = ptr->right;

        // Tr's:
        //  while (ptr->left)
        //  {
        //      push(ptr);
        //      ptr = ptr->left;
        //  }

        // while (!ptr->right)
        // {
        //     printf("%d ", ptr->data);
        //     if (isempty())
        //         return;
        //     ptr = pop();
        // }
        // printf("%d ", ptr->data);
        // ptr = ptr->right;
    }
}

void nonrecur_preorder()
{
    struct Node *ptr = root;
    while (ptr != NULL || !isempty())
    {
        while (ptr)
        {
            printf("%d ", ptr->data);
            push(ptr);
            ptr = ptr->left;
        }

        ptr = pop();
        ptr = ptr->right;
    }

    // on my own... but sucks...
    //  push(root);
    //  while (!isempty())
    //  {
    //      struct Node *temp = pop();
    //      printf("%d ", temp->data);
    //      if (temp->right)
    //          push(temp->right);
    //      if (temp->left)
    //          push(temp->left);
    //  }
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
    while (ptr)
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
    int arry[] = {5, 8, 3, 2, 1, 13, 16};

    for (int i = 0; i < sizeof(arry) / sizeof(arry[0]); i++)
    {
        add_node(arry[i]);
    }

    printf("preorder Transversal: ");
    preorder(root);
    printf("\npreorder Transversal nonrec: ");
    nonrecur_preorder();

    printf("\ninorder Transversal: ");
    inorder(root);
    printf("\ninorder Transversal nonrec: ");
    nonrecur_inorder();

    printf("\npostorder Transversal nonrec: ");
    nrec_postorder();
    printf("\npostorder Transversal: ");
    postorder(root);
    printf("hi");
}

// stack code:
void push(struct Node *ptr)
{
    ind++;
    stack[ind] = ptr;
}

struct Node *pop()
{
    struct Node *temp = stack[ind];
    ind--;
    return temp;
}

int isempty()
{
    if (ind == -1)
        return 1;
    else
        return 0;
}
