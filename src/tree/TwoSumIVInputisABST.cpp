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
    void ino(TreeNode* root, vector<int>& arr) {
        if(!root) return;
        ino(root->left, arr);
        arr.push_back(root->val);
        ino(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right) return false;
        vector<int> arr;
        ino(root, arr);
        if(k > arr[arr.size() - 1] + arr[arr.size() - 2]) return false;
        int s = 0, e = arr.size() - 1;
        while(s < e) {
            if(arr[s] + arr[e] == k) return true;
            else if(arr[s] + arr[e] < k) s++;
            else e--;
        }
        return false;
    }
};

class Solution {
public:
    bool ino(TreeNode* root, unordered_map<int, bool> &m, int k) {
        if (!root) return false;
        if(ino(root->left, m, k)) return 1;
        int want = k - root->val;
        if (m.find(want) != m.end())
            return 1;
        m[root->val] = 1;

        return ino(root->right, m, k);
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root->left && !root->right)
            return false;
        unordered_map<int, bool> m;
        return ino(root, m, k);
    }
};
