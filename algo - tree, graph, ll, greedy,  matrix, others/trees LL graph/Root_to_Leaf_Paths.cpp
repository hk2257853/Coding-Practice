/*
My working soln
*/

void getpaths(Node* root, vector<int> &path, vector<vector<int>> &res)
 {
     if(root == NULL) return;
     path.push_back(root->data);
     if(!root->left && !root->right)
     {
         res.push_back(path);
     }
     
     getpaths(root->left, path, res);
     getpaths(root->right, path, res);
     path.pop_back();
 }
 
vector<vector<int>> Paths(Node* root)
{
    vector<int> path;
    vector<vector<int>> res;
    getpaths(root, path, res);
    return res;
}

/*
someone's:
(looks memory inefficient to me)

void solve(Node* root,vector<vector<int>> &v,vector<int> temp)
 {
     temp.push_back(root->data);
     if(root->left)
     {
         solve(root->left,v,temp);
     }
     if(root->right)
     solve(root->right,v,temp);
     if(root->left==NULL && root->right==NULL)
     v.push_back(temp);
 }
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> v;
    vector<int> temp;
    solve(root,v,temp);
    return v;
}
*/