#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    int lthread; // indicates if its a child or thread
    int rthread;
};

struct Node *root = NULL;

struct Node *inpred(struct Node *node)
{
    if (node->lthread)
    {
        return node->left;
    }

    node = node->left;
    while (!node->rthread)
    {
        node = node->right;
    }
    return node;
}

struct Node *insucc(struct Node *node)
{
    if (node->rthread) // is right subtree doesn't exist, rthread will be true
    {
        return node->right;
    }

    node = node->right;
    while (!node->lthread)
    {
        node = node->left;
    }
    return node;
}

void add_node(int n)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->lthread = 1;
    newnode->rthread = 1;
    newnode->data = n;

    if (root == NULL) // case 1: insert in empty tree
    {
        root = newnode;
        newnode->left = NULL;
        newnode->right = NULL;
        return;
    }

    struct Node *ptr = root;
    while (ptr) // get at req location
    {
        if (n > ptr->data)
        {
            if (ptr->rthread == 1)
                break;
            ptr = ptr->right;
        }
        else
        {
            if (ptr->lthread == 1)
                break;
            ptr = ptr->left;
        }
    }

    if (n < ptr->data) // insert at left
    {
        newnode->left = ptr->left;
        newnode->right = ptr;
        ptr->left = newnode;
        ptr->lthread = 0;
    }
    else
    {
        newnode->right = ptr->right;
        newnode->left = ptr;
        ptr->right = newnode;
        ptr->rthread = 0;
    }
}

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

    if (ptr->lthread && ptr->rthread) // leaf node
    {
        if (prev->left == ptr)
        {
            prev->left = ptr->left;
            prev->lthread = 1;
        }
        else
        {
            prev->right = ptr->right;
            prev->rthread = 1;
        }
        free(ptr);
    }
    else if (ptr->lthread && !ptr->rthread) // has one child
    {                                       // has right subtree
        if (prev->left == ptr)
        {
            prev->left = ptr->right;
        }
        else
        {
            prev->right = ptr->right;
        }
        // changing thread for succ
        struct Node *pred = inpred(ptr);
        struct Node *succ = insucc(ptr);
        succ->left = pred;
        free(ptr);
    }
    else if (ptr->rthread && !ptr->lthread)
    {
        if (prev->left == ptr)
        {
            prev->left = ptr->left;
        }
        else
        {
            prev->right = ptr->left;
        }
        // changing thread for pred
        struct Node *pred = inpred(ptr);
        struct Node *succ = insucc(ptr);
        pred->right = succ;
        free(ptr);
    }
    else if (!ptr->lthread && !ptr->rthread) // 2 child
    {
        struct Node *minptr = ptr->right;
        while (!minptr->lthread)
        {
            minptr = minptr->left;
        }

        int minptrdata = minptr->data; // by doing this little change it started working!
        deletenode(root, minptrdata);  // Earlier I 1st exchanged data n then deleted due
        ptr->data = minptrdata;        // to which the nos were no more in that sorted way
    }
}

void preorder()
{
    struct Node *ptr = root;

    while (ptr)
    {
        while (ptr->lthread != 1)
        {
            printf("%d ", ptr->data);
            ptr = ptr->left;
        }
        printf("%d ", ptr->data);

        while (ptr->right != NULL && ptr->rthread == 1)
        {
            ptr = ptr->right;
        }
        ptr = ptr->right;
    }
}

int main()
{
    int option;
    while (1)
    {
        printf("0 Insert elements \n");
        printf("1 Insert \n");
        printf("2 Delete \n");
        printf("3 Preorder \n");
        scanf("%d", &option);
        int num, Telements;

        switch (option)
        {
        case 0:
            printf("Enter total elements: ");
            scanf("%d", &Telements);
            for (int i = 0; i < Telements; i++)
            {
                printf("Enter number to insert: ");
                scanf("%d", &num);
                add_node(num);
            }
            break;
        case 1:
            printf("Enter number to insert: ");
            scanf("%d", &num);
            add_node(num);
            break;
        case 2:
            printf("Enter number to Delete: ");
            scanf("%d", &num);
            deletenode(root, num);
            break;
        case 3:
            printf("Elements are: ");
            preorder(root);
            break;
        }

        printf("\n\n");
    }
}