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

    void sol(TreeNode* root, int targetSum, bool &ans, int sum) {
        if(!root) return;
        sum += root->val;
        if((!root->left && !root->right) && sum == targetSum) {
            ans = 1;
            return;
        }; 
        sol(root->left, targetSum, ans, sum);
        sol(root->right, targetSum, ans, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        // if((!root->left && !root->right) && root->val == targetSum) return 1;
        // if((root->left || root->right) && root->val == targetSum) return 0;
        bool ans = 0;
        sol(root, targetSum, ans, 0);
        return ans;
    }
};
