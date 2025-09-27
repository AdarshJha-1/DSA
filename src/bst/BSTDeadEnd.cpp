/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
  
    bool sol(Node *root, int l, int h) {
        if(!root) {
            return false;
        }
        
        if(!root->left && !root->right) {
            if(root->data - l == 1 && h - root->data == 1) {
                return true;
            }
        }
            
        
        return sol(root->left, l, root->data) || sol(root->right, root->data, h);
    }
    
    bool isDeadEnd(Node *root) {
        return sol(root, 0, INT_MAX);;
    }
};
