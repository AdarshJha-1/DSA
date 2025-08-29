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
    bool isParent(TreeNode* root, int x, int y) {
        if(!root) return 0;
        if(root->left && root->right) {
            if(root->left->val == x && root->right->val == y) return 1;
            if(root->left->val == y && root->right->val == x) return 1;
        }
        return isParent(root->left, x, y) || isParent(root->right, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int lvl = 0;
        int l1 = -1, l2 = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->val == x) l1 = lvl;
                if(node->val == y) l2 = lvl;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            lvl++;
            if(l1 != -1 && l2 != -1) break;

        }
        if(l1 == -1 || l2 == -1) return 0;
        if(l1 != l2) return 0;

        return !isParent(root, x, y);
    }
};
