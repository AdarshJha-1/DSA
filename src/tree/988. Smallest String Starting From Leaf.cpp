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
    string ans = "~";
    void sol(TreeNode* root, string& currStr)
    {
        if(!root)
        {
            return;
        }

        currStr.push_back(root->val + 'a');

        if(!root->left && !root->right)
        {
            string temp = currStr;
            reverse(temp.begin(), temp.end());
            if(temp < ans)
            {
                ans = temp;
            }
        }
        sol(root->left, currStr);
        sol(root->right, currStr);
        currStr.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        if(!root)
        {
            return "";
        }
        string temp = "";
        sol(root, temp);
        return ans;  
    }
};
