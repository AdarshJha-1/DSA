/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    
    void sol(Node* root, int &k, int &ans) {
        if(!root) return;
        sol(root->right, k, ans);
        if(k == 0) return;
        ans = root->data;
        k--;
        sol(root->left, k, ans);
    }
  
    int kthLargest(Node *root, int k) {
        int ans = 0;
        sol(root, k, ans);
        return ans;
    }
};
