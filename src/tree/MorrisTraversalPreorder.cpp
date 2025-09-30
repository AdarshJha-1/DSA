/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        Node *curr = root;
        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                ans.push_back(curr->data);
                Node *temp = curr->left;
                while(temp->right) {
                    temp = temp->right;
                }
                if(!temp->right) {
                    temp->right = curr->right;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};


/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        Node *curr = root;
        
        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                
                Node *temp = curr->left;
                while(temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                
                if(!temp->right) {
                    ans.push_back(curr->data);
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    temp->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
