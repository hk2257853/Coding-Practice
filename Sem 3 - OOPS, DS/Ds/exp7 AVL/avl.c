#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    int height;
};

int getheight(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getmax(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *right_rotate(struct Node *node)
{
    struct Node *child = node->left;
    node->left = child->right;
    child->right = node;

    node->height = getmax(getheight(node->left), getheight(node->right)) + 1;
    child->height = getmax(getheight(node->left), getheight(node->right)) + 1;

    return child;
}

int getbalancefac(struct Node *node)
{
    if (!node)
        return 0;
    return getheight(node->left) - getheight(node->right);
}

struct Node *left_rotate(struct Node *node)
{
    struct Node *child = node->right;
    node->right = child->left;
    child->left = node;

    node->height = getmax(getheight(node->left), getheight(node->right)) + 1;
    child->height = getmax(getheight(node->left), getheight(node->right)) + 1;

    return child;
}

struct Node *insert(struct Node *node, int num) //TODO: draw dig for simpler case n try to orally write the code
{
    if (!node) // base case (if root was null...?)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = num;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->height = 1;
        return newnode;
    }

    // normal recursion logic
    if (num > node->data)
        node->right = insert(node->right, num);
    else
        node->left = insert(node->left, num);

    // ***after inserting need to update the height!
    node->height = 1 + getmax(getheight(node->left), getheight(node->right));

    // balancing part 
    int balancefac = getbalancefac(node);

    // Left Left Case
    if (balancefac > 1 && num < node->left->data)
        return right_rotate(node);

    // Right Right Case
    if (balancefac < -1 && num > node->right->data)
        return left_rotate(node);

    // Left Right Case
    if (balancefac > 1 && num > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balancefac < -1 && num < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deletenode(struct Node *node, int num)
{
    if (!node)
    {
        return node;
    }
    
    //TODO: re see recursive deletion part.
    // Its just normal like BST but recursively done here.

    if (num > node->data)
        node->right = deletenode(node->right, num);
    else if (num < node->data)
        node->left = deletenode(node->left, num);
    else // I reached the node I wanna delete  
    {
        // node with only one child or no child
        if (node->left == NULL || node->right == NULL)
        {
            struct Node *temp = node->left ? node->left : node->right;

            // No child case
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else               // One child case
                *node = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children
            // inorder successor (min in the right subtree)
            struct Node *temp = minValueNode(node->right);

            // Copy the inorder successor's
            // data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deletenode(node->right, temp->data);
        }
    }

    // If the tree had only one node // isn't this the base case?
    // then return
    if (node == NULL)
        return node;

    // ***After deletion update height for the node & do the rotations!!
    node->height = 1 + getmax(getheight(node->left), getheight(node->right));

    // balancing part
    int balancefac = getbalancefac(node);

    // Left Left Case
    if (balancefac > 1 && num < node->left->data)
        return right_rotate(node);

    // Right Right Case
    if (balancefac < -1 && num > node->right->data)
        return left_rotate(node);

    // Left Right Case
    if (balancefac > 1 && num > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balancefac < -1 && num < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void preorder(struct Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void displaytree(struct Node *p, int lvl)
{
    int i;
    if (p == NULL)
        return;

    displaytree(p->right, lvl + 1);
    printf("\n\n");
    for (int i = 0; i < lvl; i++)
    {
        printf("\t");
    }
    printf("%d", p->data);
    displaytree(p->left, lvl + 1);
}

int main()
{
    struct Node *root = NULL;

    int option;
    while (1)
    {
        printf("0 Insert elements \n");
        printf("1 Insert \n");
        printf("2 Delete \n");
        printf("3 Preorder \n");
        printf("4 Display tree \n");
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
                root = insert(root, num);
            }
            break;
        case 1:
            printf("Enter number to insert: ");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printf("Enter number to Delete: ");
            scanf("%d", &num);
            root = deletenode(root, num);
            break;
        case 3:
            printf("Elements are: ");
            preorder(root);
            break;
        case 4:
            displaytree(root, 0);
            break;
        }

        printf("\n\n");
    }
}