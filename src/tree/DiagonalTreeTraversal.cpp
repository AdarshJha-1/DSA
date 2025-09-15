/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    
    void left(Node* root, int &l, int curr) {
        if(!root) return;
        l = max(l, curr);
        left(root->left, l, curr + 1);
        left(root->right, l, curr);
    }
    
    void sol(Node* root,  int pos, vector<vector<int>> &temp) {
        if(!root) return;
        temp[pos].push_back(root->data);
        sol(root->left, pos + 1, temp);
        sol(root->right, pos, temp);
    }
    
    vector<int> diagonal(Node *root) {
        int l;
        left(root, l, 0);
        vector<vector<int>> temp(l + 1);
        sol(root, 0, temp);
        vector<int> ans;
        for(auto row : temp) {
            for(auto val : row) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
