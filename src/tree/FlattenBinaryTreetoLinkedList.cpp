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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* temp = curr->left;
                while (temp->right) {
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
