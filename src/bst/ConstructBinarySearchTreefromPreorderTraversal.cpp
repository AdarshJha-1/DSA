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

    TreeNode* create(TreeNode* root, int data) {
        if(!root) {
            return new TreeNode(data);
        }
        if(data < root->val) {
            root->left = create(root->left, data);
            return root;
        } else {
            root->right = create(root->right, data);
            return root;
        } 
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = nullptr;
        for(int i = 0; i < preorder.size(); i++) {
            root = create(root, preorder[i]);
        }
        return root;
    }
};
