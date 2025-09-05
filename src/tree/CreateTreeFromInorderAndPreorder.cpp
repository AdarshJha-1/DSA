// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int findPosIno(vector<int>inorder, int target ,int  inS, int inE) {
        for(int i = inS; i <= inE; i++) {
            if(target == inorder[i]) {
                return i;
            }
        }
        return -1;
    }
    Node* Tree(vector<int> &inorder, vector<int> &preorder, int inS, int inE, int idx) {
        
        if(inS > inE) return nullptr;
        Node* root = new Node(preorder[idx]);
        int pos = findPosIno(inorder, preorder[idx], inS, inE);
        root->left = Tree(inorder, preorder, inS, pos - 1, idx + 1);
        root->right = Tree(inorder, preorder, pos + 1, inE, idx + (pos - inS) + 1);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        Node* root = Tree(inorder, preorder, 0, inorder.size() - 1, 0);
        return root;
    }
};
