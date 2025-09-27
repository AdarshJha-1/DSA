class Solution {
  public:
 
    void sol(Node* root, int l, int h, vector<int> &ans) {
        if(!root) return;
        sol(root->left, l, h, ans);
        if(root->data >= l && root->data <= h) {
            ans.push_back(root->data);
        }
        sol(root->right, l, h, ans);
    }

    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        sol(root, low, high, ans);
        return ans;
    }
};

class Solution {
  public:
 
    void sol(Node* root, int l, int h, vector<int> &ans) {
        if(!root) return;
        
        if(root->data > l && root->data > h) {
            sol(root->left, l, h, ans);
        } else if(root->data < l && root->data < h) {
            sol(root->right, l, h, ans);
        } else {
            sol(root->left, l, h, ans);
            if(root->data >= l && root->data <= h) {
                ans.push_back(root->data);
            }
            sol(root->right, l, h, ans);
        }
    }

    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        sol(root, low, high, ans);
        return ans;
    }
};
