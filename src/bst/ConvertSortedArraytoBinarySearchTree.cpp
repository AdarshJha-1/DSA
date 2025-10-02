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

    TreeNode* sol(vector<int>&nums, int s, int e) {
        if(s > e) return nullptr;
        int m = s + (e - s + 1) / 2; 
        TreeNode *root = new TreeNode(nums[m]);
        root->left = sol(nums, s, m -1);
        root->right = sol(nums, m + 1, e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sol(nums, 0, nums.size() - 1);
    }
};
