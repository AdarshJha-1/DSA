/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inor(Node* root, vector<int>& ans) {
        if(root == nullptr) return;
        inor(root->left, ans);
        ans.push_back(root->data);
        inor(root->right, ans);
    }

    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inor(root, ans);
        return ans;
    }
};
