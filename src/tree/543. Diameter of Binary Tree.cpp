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
    // i am thinking like each node -> root -> calculate left and right add check for ans ?? using max then from left and right return max to parent to see if parent as root can have valid bigger ans ?? let see

    int sol(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        int left = sol(root->left, ans);
        int right = sol(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        sol(root, ans);
        return ans;
    }
};