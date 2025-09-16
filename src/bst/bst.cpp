#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;

    }
};

Node* createFromArray(Node* root, int data) {
    if(!root) {
        return new Node(data);
    }

    if(data < root->data) {
        root->left = createFromArray(root->left, data);
    } else {
        root->right=  createFromArray(root->right, data);
    }
    return root;
}

void printBST(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    printBST(root->left);
    printBST(root->right);
}


int main() {
    vector<int> arr = {6,3,11,5,7,18,12,2};
    Node *root = nullptr;
    for(int d : arr) {
        root = createFromArray(root, d);
    }

    printBST(root);

    return 0;
}
