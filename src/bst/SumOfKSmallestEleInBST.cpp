// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1


void sol(Node* root, int &ans, int &k) {
    if(!root) return;
    sol(root->left, ans, k);
    if(k == 0) return;
    ans += root->data;
    k--;
    sol(root->right, ans, k);
}

int sum(Node* root, int k) {
    int ans = 0;
    sol(root, ans, k);
    return ans;
}
