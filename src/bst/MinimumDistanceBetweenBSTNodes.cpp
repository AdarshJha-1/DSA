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
    void bt(TreeNode* root, vector<int> &nums) {
        if(!root) return;
        bt(root->left, nums);
        nums.push_back(root->val);
        bt(root->right, nums);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        bt(root, nums);
        int minVal = INT_MAX;

        for(int i = 1; i < nums.size(); i++) {
           minVal = min(minVal, (nums[i] - nums[i - 1]));
        }
        return minVal;
    }
};
