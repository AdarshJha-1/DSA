// Structure of node
/*class Node {
   public:
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
  
    int countNode(Node* root) {
        if(!root) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
    
    bool CBT(Node* tree, int i, int n) {
        if(!tree) return 1;
        if(i >= n) return 0;
        return CBT(tree->left, i * 2 + 1, n) && CBT(tree->right, i * 2 + 2, n);
    }
    
    bool con(Node* tree) {
        if(!tree) return 1;
        if(tree->left) {
            if(tree->data < tree->left->data) return 0;
        }
        if(tree->right) {
            if(tree->data < tree->right->data) return 0;
        }
        return con(tree->left) && con(tree->right);
    }
    
    bool isHeap(Node* tree) {
        int count = countNode(tree);
        bool cbt = CBT(tree, 0, count);
        if(!cbt) return 0;
        if(!con(tree)) return 0;
        return 1;
    }
};
