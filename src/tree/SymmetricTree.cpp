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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> arr;
            int n = q.size();
            while (n--) {
                if (q.front() != nullptr) {
                    arr.push_back(q.front()->val);
                    if (q.front()->left) {
                        q.push(q.front()->left);
                    } else {
                        q.push(nullptr);
                    }

                    if (q.front()->right) {
                        q.push(q.front()->right);
                    } else {
                        q.push(nullptr);
                    }
                } else {
                    arr.push_back(INT_MIN);
                }

                q.pop();
            }

            int s = 0, e = arr.size() - 1;
            while (s <= e) {
                if (arr[s] != arr[e])
                    return false;
                s++;
                e--;
            }
        }
        return true;
    }
};
