/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* merge(Node *h1, Node *h2) {
        Node *head = new Node(0);
        Node *tail = head;
        while(h1 && h2) {
            if(h1->data <= h2->data) {
                tail->bottom = h1;
                h1 = h1->bottom;
                tail = tail->bottom;
                tail->bottom = nullptr;
            } else {
                tail->bottom = h2;
                h2 = h2->bottom;
                tail = tail->bottom;
                tail->bottom = nullptr;
            }
        }
        if(h1) {
            tail->bottom = h1;
        }
        if(h2) {
            tail->bottom = h2;
        }
        
        return head->bottom;
    }
  
    Node *flatten(Node *root) {
        Node *h1, *h2, *h3;
        while(root->next) {
            h1 = root, h2 = root->next, h3 = root->next->next;
            h1->next = nullptr, h2->next = nullptr;
            root = merge(h1, h2);
            root->next = h3;
        }
        return root;
    }
};
