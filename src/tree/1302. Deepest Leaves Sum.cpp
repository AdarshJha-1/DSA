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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    void findSum(TreeNode *root, int currD, int maxD, int &sum)
    {
        if (!root)
        {
            return;
        }
        if (currD == maxD)
        {
            sum += root->val;
        }
        findSum(root->left, currD + 1, maxD, sum);
        findSum(root->right, currD + 1, maxD, sum);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        int maxD = maxDepth(root); // :)
        int sum = 0;
        findSum(root, 1, maxD, sum);
        return sum;
    }
};