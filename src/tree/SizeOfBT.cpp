/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    void si(Node* node, int &count) {
        if(node == nullptr) return;
        count++;
        si(node->left, count);
        si(node->right, count);
    }
    int getSize(Node* node) {
        int count = 0;
        si(node, count);
        return count;
    }
};
