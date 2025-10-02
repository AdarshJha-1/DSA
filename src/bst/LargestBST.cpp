/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    void ino(Node *root, vector<int>& arr) {
        if(!root) return;
        ino(root->left, arr);
        arr.push_back(root->data);
        ino(root->right, arr);
    }
    
    int largestBst(Node *root) {
        vector<int> arr;
        ino(root, arr);
        int ans = 0;
        int curr = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > arr[i - 1]) {
                ans = max(ans, curr);
                curr = 1;
            } else {
                curr++;
            }
        }
        
        ans = max(curr, ans);
        return ans;
    }
};
