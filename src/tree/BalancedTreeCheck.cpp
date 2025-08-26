/*

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    int ans(Node* root, bool &v) {
        if(!root) return 0;
        int l = ans(root->left, v);
        int r = ans(root->right, v);
        
        int diff = l - r;
        if(diff != -1 && diff != 0 && diff != 1) {
            v = 0;
        }
        return 1 + max(l , r);
    }
    bool isBalanced(Node* root) {
        bool v = 1;
        ans(root, v);
        return v;
        
    }
};
