/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isIdentical(Node* root1, Node* root2) {
        // code here
        if(!root1 && !root2) return 1;
        if((!root1 && root2) || (root1 && !root2)) return 0;
        if(root1->data != root2->data) return 0;
        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
};
