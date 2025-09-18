/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, queue<TreeNode*> &q) {
        if(!root) return;
        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }

    TreeNode* sol(TreeNode* root, queue<TreeNode*> &q) {
        if(q.empty()) return nullptr;
        root = q.front();
        q.pop();
        root->left = nullptr;
        root->right = sol(root->right, q);
        return root;
    }

    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        preorder(root, q);
        root = sol(root, q);
    }
};
