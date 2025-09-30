// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node *curr = root;
        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                Node* temp = curr->left;
                while(temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                
                if(!temp->right) {
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    ans.push_back(curr->data);
                    temp->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};
