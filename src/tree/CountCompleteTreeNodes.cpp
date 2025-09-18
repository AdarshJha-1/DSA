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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right); 
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int cl(TreeNode* root) {
        if(!root) return 0;
        return 1 + cl(root->left);   
    }

    int cr(TreeNode* root) {
        if(!root) return 0;
        return 1 + cr(root->right);   
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = cl(root);
        int rh = cr(root);
        if(lh == rh) {
            int pow = 1;
            while(lh--) {
                pow *= 2;
            }

            return pow - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
