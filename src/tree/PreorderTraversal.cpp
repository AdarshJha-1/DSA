/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void pre(Node* root, vector<int>& ans) {
        if(root == nullptr) return;
        ans.push_back(root->data);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};
