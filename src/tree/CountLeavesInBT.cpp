/* A binary tree node has data, pointer to left child
and a pointer to right child
struct Node
{
 int data;
 Node* left;
 Node* right;
}; */

// Class Solution
class Solution {
public:
 // Function to count the number of leaf nodes in a binary tree.
 void leaves(Node* root, int &count) {
     if(root == nullptr) {
         return;
     }
     if(root->left == nullptr && root->right == nullptr) {
         count++;
         return;
     }
     leaves(root->left, count);
     leaves(root->right, count);
 }
     
 int countLeaves(Node* root) {
     // write code here
     // int count = 0;
     // leaves(root, count);
     // return count;
     
     if(root == nullptr) return 0; 
     if(root->left == nullptr && root->right == nullptr) return 1;
     return countLeaves(root->left) + countLeaves(root->right);

 }
};
