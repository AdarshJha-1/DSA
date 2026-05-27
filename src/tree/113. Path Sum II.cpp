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
    vector<vector<int>> ans;

    void sol(TreeNode* root, int targetSum, vector<int>& path, int currSum) 
    {   
        if(!root)
        {
            return;
        }

        path.push_back(root->val);
        currSum += root->val;
        if(currSum == targetSum && !root->left && !root->right)
        {
            ans.push_back(path);
        }
        else
        {
            sol(root->left, targetSum, path, currSum);
            sol(root->right, targetSum, path, currSum);   
        }
        path.pop_back();     
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {   
        vector<int> path;
        sol(root, targetSum, path, 0);
        return ans;
    }
};
