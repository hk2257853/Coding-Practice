int lsum(Node *root, int left)
{
    if(root == NULL) return 0;
    if(!root->left && !root->right && left) return root->data; // the only left leaf node...
    return lsum(root->left, 1) + lsum(root->right, 0); // add up sum given by left & right subtree    
}

int leftLeavesSum(Node *root)
{
    return lsum(root, 0);
}

/*
From gfg, makes more sense ig
void leftLeavesSumRec(Node *root, bool isleft, int *sum)
{
    if (!root) return;
 
    // Check whether this node is a leaf node and is left.
    if (!root->left && !root->right && isleft)
        *sum += root->key;
 
    // Pass 1 for left and 0 for right
    leftLeavesSumRec(root->left,  1, sum);
    leftLeavesSumRec(root->right, 0, sum);
}

*/