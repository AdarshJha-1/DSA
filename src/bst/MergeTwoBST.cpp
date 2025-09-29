/*
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
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void ino(Node* root, vector<int> &arr) {
        if(!root) return;
        ino(root->left, arr);
        arr.push_back(root->data);
        ino(root->right, arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans, a1, a2;
        ino(root1, a1);
        ino(root2, a2);
        
        int i = 0, j = 0;
        while(i < a1.size() && j < a2.size()) {
            if(a1[i] < a2[j]) {
                ans.push_back(a1[i++]);
            } else {
                ans.push_back(a2[j++]);
            }
        }
        
        while(i != a1.size()) {
            ans.push_back(a1[i++]);
        }
        
        while(j != a2.size()) {
            ans.push_back(a2[j++]);
        }
        
        return ans;
    }
};
