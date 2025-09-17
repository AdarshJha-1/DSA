/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node *deleteNode(Node *root, int x) {
        if(!root) return nullptr;
        if(x < root->data) {
            root->left = deleteNode(root->left, x);
            return root;
        } else if(x > root->data) {
            root->right = deleteNode(root->right, x);
            return root;
        } else {
            if(!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if(!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(!root->left && !root->right) {
                delete root;
                return nullptr;
            } else {
                Node* parent = root;
                Node* child = root->right;
                while(child->left) {
                    parent = child;
                    child = child->left;
                }
                
                if(parent == root) {
                    child->left = parent->left;
                    return child;
                } else {
                    parent->left = child->right;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
        
    }
};
