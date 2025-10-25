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
    int n;
    TreeNode* sol(string& traversal, int d, int &i) {
        if(i >= n) return nullptr;
        int j = i;
        while(j < n && traversal[j] == '-') j++;
        if(d != j - i) return nullptr;
        i = j;
        int num = 0;
        int k = i;
        while(k < n && traversal[k] != '-') {
            num = num * 10 + (traversal[k] - '0');
            k++;
        }
        i = k;
        TreeNode *node = new TreeNode(num);
        node->left = sol(traversal, d + 1, i);
        node->right = sol(traversal, d + 1, i);

        return node;        
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int d = 0;
        int i = 0;
        n = traversal.size();
        return sol(traversal, d, i);
    }
};
