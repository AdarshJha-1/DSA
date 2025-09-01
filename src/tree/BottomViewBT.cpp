/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    
    void lr(Node* root, int curr, int &l, int &r) {
        if(!root) return;
        l = min(curr, l);
        r = max(curr, r);
        lr(root->left, curr - 1, l, r);
        lr(root->right, curr + 1, l, r);
    } 
  
    void bV(Node* root, vector<int>&ans, vector<int>&lvl, int pos, int clvl) {
        if(!root) return;
        if(clvl > lvl[pos]) {
            ans[pos] = root->data;
            lvl[pos] = clvl;
        }
        bV(root->left, ans, lvl, pos - 1, clvl + 1);
        bV(root->right, ans, lvl, pos + 1, clvl + 1);
    }
    vector<int> bottomView(Node *root) {
        int l = 0, r = 0;
        lr(root, 0, l, r);
        vector<int> ans(r - l + 1);
        vector<int> lvl(r - l + 1, INT_MIN);
        bV(root, ans, lvl, (-1 * l), 0);
        return ans;
    }
};
