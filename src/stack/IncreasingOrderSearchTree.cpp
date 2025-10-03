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
    void util(TreeNode* root, stack<TreeNode*>& st) {
        if (!root)
            return;
        util(root->right, st);
        st.push(root);
        util(root->left, st);
    }

    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        util(root, st);
        root = st.top();
        st.pop();
        root->left = nullptr;
        TreeNode* temp = root;
        while (!st.empty()) {
            temp->right = st.top();
            temp->right->left = nullptr;
            temp = temp->right;
            st.pop();
        }
        return root;
    }
};
