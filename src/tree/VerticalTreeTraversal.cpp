/*
// Tree Node
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
  
    void lr(Node* root, int curr, int &l, int &r) {
        if(!root) return;
        l = min(l, curr);
        r = max(r, curr);
        
        lr(root->left, curr - 1, l, r);
        lr(root->right, curr + 1, l, r);
    }
    vector<vector<int>> verticalOrder(Node *root) {
        int l = 0, r = 0;
        lr(root, 0, l, r);
        
        vector<vector<int>> ans(r - l + 1);
        queue<Node*> q;
        q.push(root);
        queue<int> idx;
        idx.push(-1 * l);
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            int i = idx.front();
            idx.pop();
            
            ans[i].push_back(temp->data);
            if(temp->left) {
                q.push(temp->left);
                idx.push(i - 1);
            }
            if(temp->right) {
                q.push(temp->right);
                idx.push(i + 1);
            }
        }
        
        return ans;
        
    }
};
