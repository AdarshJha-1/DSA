/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int find(vector<int>& inorder, int target, int inS, int inE) {
        for(int i = inS; i <= inE; i++) {
            if(inorder[i] == target) return i;
        }
        return -1;
    }
    
    Node* Tree(vector<int> &inorder, vector<int> &postorder, int inS, int inE, int idx) {
        if(inS > inE) return nullptr;
        Node* root = new Node(postorder[idx]);
        int pos = find(inorder, postorder[idx], inS, inE);
        root->right = Tree(inorder, postorder, pos + 1, inE, idx -1);
        root->left = Tree(inorder, postorder, inS, pos -1 , idx - (inE - pos) - 1);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        Node* root = Tree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
        return root;
        
    }
};
