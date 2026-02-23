/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    void ind(Node *root, vector<int> &arr)
    {
        if (!root)
            return;
        ind(root->left, arr);
        arr.push_back(root->data);
        ind(root->right, arr);
    }

    // Brute force
    Node *flattenBST(Node *root)
    {
        vector<int> temp;
        ind(root, temp);
        root->data = temp[0];
        Node *tail = root;
        root->left = nullptr;
        for (int i = 1; i < temp.size(); i++)
        {
            tail->right = new Node(temp[i]);
            tail = tail->right;
        }
        return root;
    }
};