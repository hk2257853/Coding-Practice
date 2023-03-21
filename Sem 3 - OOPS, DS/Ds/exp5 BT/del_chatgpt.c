struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *deleteNode(Node *root, int key)
{
    Node *parent = nullptr;
    Node *curr = root;
    while (curr != nullptr && curr->data != key)
    {
        parent = curr;
        if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (curr == nullptr)
    {
        return root;
    }
    if (curr->left == nullptr)
    {
        if (parent == nullptr)
        {
            root = curr->right;
        }
        else if (curr == parent->left)
        {
            parent->left = curr->right;
        }
        else
        {
            parent->right = curr->right;
        }
        delete curr;
    }
    else if (curr->right == nullptr)
    {
        if (parent == nullptr)
        {
            root = curr->left;
        }
        else if (curr == parent->left)
        {
            parent->left = curr->left;
        }
        else
        {
            parent->right = curr->left;
        }
        delete curr;
    }
    else
    {
        Node *minRight = curr->right;
        while (minRight->left != nullptr)
        {
            parent = minRight;
            minRight = minRight->left;
        }
        curr->data = minRight->data;
        if (parent->left == minRight)
        {
            parent->left = minRight->right;
        }
        else
        {
            parent->right = minRight->right;
        }
        delete minRight;
    }
    return root;
}
