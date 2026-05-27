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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        
        bool shouldEnd = false;  // whene val = 0 mark true then every next node have to be zero
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(!shouldEnd && curr->val == 0)
                {
                    shouldEnd = true;
                }
                if(shouldEnd)
                {
                    if(curr->val != 0)
                    {
                        return false;
                    }
                }
                else
                {
                    if(curr->left)
                    {
                        q.push(curr->left);
                    }
                    else
                    {
                        q.push(new TreeNode(0));
                    }
                    if(curr->right)
                    {
                        q.push(curr->right);
                    }
                    else
                    {
                        q.push(new TreeNode(0));
                    }
                }
            }
        }

        return true;
    }
};
