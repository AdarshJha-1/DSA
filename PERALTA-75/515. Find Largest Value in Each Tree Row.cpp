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
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int maxE = INT_MIN;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                maxE = max(maxE, temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(maxE);
        }
        return ans;
    }
};