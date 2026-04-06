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
class Solution 
{
public:

    int ans = INT_MIN;

    int sol(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int leftSum = max(0, sol(root->left));
        int rightSum = max(0, sol(root->right));
        ans = max(ans, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) 
    {
       sol(root);
       return ans;
    }
};