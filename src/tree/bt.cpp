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
};

int main() {

    BT b;
    b.createBT();

    return 0;
}
