/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    void post(Node* root, vector<int>& ans) {
        if(root == nullptr) return;
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }
};
