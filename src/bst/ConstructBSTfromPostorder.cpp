/*struct Node
{
    int data;
    Node *left, *right;
};*/


Node* sol(Node* root, int val) {
    if(!root) return new Node(val);
    if(val > root->data) {
        root->right = sol(root->right, val);
        return root;
    }
    
     if(val < root->data) {
        root->left = sol(root->left, val);
        return root;
    }
}


Node *constructTree(int post[], int size) {
    Node* root = nullptr;
    for(int i = size - 1; i >= 0; i--) {
        root = sol(root, post[i]);
    }
    
    return root;
}
