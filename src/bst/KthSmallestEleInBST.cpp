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
    void inorder(TreeNode* root, vector<int> &temp) {
        if(!root) return;
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        inorder(root, temp);
        return temp[k - 1];
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int k, int& ans, int &i) {
        if (!root) return;
        inorder(root->left, k, ans, i);
        i++;
        if (k == i) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans, i);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int i = 0;
        inorder(root, k, ans, i);
        return ans;
    }
};
