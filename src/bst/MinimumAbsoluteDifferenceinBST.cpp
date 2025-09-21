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
    void sol(TreeNode* root, int& prev, int& ans) {
        if (!root)
            return;
        sol(root->left, prev, ans);
        ans = min(ans, (root->val - prev));
        prev = root->val;
        sol(root->right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MIN / 2;
        int ans = INT_MAX;
        sol(root, prev, ans);
        return ans;
    }
};
