int halfinfo(Node *root)
{
    if(!root->right && !root->left) return 0;
    if(root->right && root->left) return 0;
    if(root->left) return 1;
    if(root->right) return 2;
}

void delhalf(Node *root, Node *prev, int left) 
// putting in funct about left/right makes code really easy & clean!
{
    // doen't take care of EDGE case:
    // if root has 1 child.
    
    if(!root) return;
    
    int info = halfinfo(root);
    if(info == 1)
    {
        if(left) // left child
        {
            prev->left = root->left;
        }
        else
        {
            prev->right = root->left;
        }
    }
    else if(info == 2)
    {
        if(left) // left child
        {
            prev->left = root->right;
        }
        else
        {
            prev->right = root->right;
        }
    }
    
    delhalf(root->left, root, 1);
    delhalf(root->right, root, 0);
}

// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root)
{
    Node *prev;
    delhalf(root, prev, 0);
    return root;
}