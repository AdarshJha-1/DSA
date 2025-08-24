/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    void sum(Node* root, int &s) {
        if(root == nullptr) return;
        s += root->data;
        sum(root->left, s);
        sum(root->right, s);
    }
    int sumBT(Node* root) {
        int s = 0;
        sum(root, s);
        return s;
    }
};
