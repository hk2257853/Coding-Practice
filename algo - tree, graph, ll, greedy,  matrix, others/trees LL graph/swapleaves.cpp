class Solution
{
public:
    void getleaves(Node *root, vector<int> &leaves)
    {
        if(!root) return; // return NULL gave unknown compilation error!!
        if(!root->right && !root->left) leaves.push_back(root->data);
        getleaves(root->left, leaves); // I wrote ->right first... that disturbed the order!!
        getleaves(root->right, leaves);
        
    }
    
    void putleaves(Node *root, vector<int> &leaves, int &ind)
    {
        if(!root) return;
        if(!root->right && !root->left) 
        {
            root->data = leaves[ind];
            ind++;
        }
        putleaves(root->left, leaves, ind);
        putleaves(root->right, leaves, ind);
        
    }
    
    void pairwiseSwap(Node *root)
    {
        vector<int> leaves;
        getleaves(root, leaves);
        
        // do the swapping
        int a = 0, b = 1;
        while(a < leaves.size() && b < leaves.size())
        {
            swap(leaves[a], leaves[b]);
            a += 2;
            b += 2;
        }
        
        int ind = 0;
        putleaves(root, leaves, ind);
        
    }
};