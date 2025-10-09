
// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
  
    void ino(Node *root, vector<int> &temp) {
        if(!root) return;
        ino(root->left, temp);
        temp.push_back(root->data);
        ino(root->right, temp);
        
    }
    
    void sol(Node *root, vector<int> &temp, int &i) {
        if(!root) return;
        sol(root->left, temp, i);
        sol(root->right, temp, i);
        root->data = temp[i++];
    }
    void convertToMaxHeapUtil(Node* root) {
        vector<int> temp;
        ino(root, temp);
        int i = 0;
        sol(root, temp, i);   
    }
};
