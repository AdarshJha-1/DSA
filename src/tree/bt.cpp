#include <iostream>
#include <queue>

class Node {
public:
    Node* left;
    int data;
    Node* right;

    Node(int data) {
        this->left = nullptr;
        this->data = data;
        this->right = nullptr;
    }
};

class BT {

public:
    Node* root;
    void createBT() {
        std::queue<Node*> q;
        int d;
        std::cout << "Enter root node element: ";
        std::cin >> d;
        this->root = new Node(d);
        q.push(root);

        while(!q.empty()) {
            int d1, d2;
            std::cout << "Enter left node data: ";
            std::cin >> d1;

            std::cout << "Enter right node data: ";
            std::cin >> d2;

            Node* temp = q.front();
            if(d1 != -1) {
                temp->left = new Node(d1);
                q.push(temp->left);
            }
            if(d2 != -1) {
                temp->right = new Node(d2);
                q.push(temp->right);
            }
            q.pop();
        }
        std::cout << "Binary Tree Created Successfully." << std::endl;
    }


    Node* createBt() {
        int data;
        std::cout << "Enter the element: ";
        std::cin >> data;
        if(data == -1) return nullptr;
        Node* node = new Node(data);
        node->left = createBt();
        node->right = createBt();
        return node;
    }

    void preorder(Node* root) {
        if(root == nullptr) return;
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root) {
        if(root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
    void inorder(Node* root) {
        if(root == nullptr) return;
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {

    BT b;
    b.root = b.createBt();
    b.preorder(b.root);
    std::cout << std::endl;
    b.postorder(b.root);
    std::cout << std::endl;
    b.inorder(b.root);
    std::cout << std::endl;
    return 0;
}
