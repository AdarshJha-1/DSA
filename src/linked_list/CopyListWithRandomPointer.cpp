/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cr = head;
        while(cr) {
            Node *t = new Node(cr->val);
            t->next = cr->next;
            cr->next = t;
            cr = t->next;
        }
        cr = head;
        while(cr) {
            Node *f = cr->next;
            if(!cr->random) {
                f->random = nullptr;
            } else {
                f->random = cr->random->next;
            }
            cr = f->next; 
        }

        cr = head;
        Node *root = new Node(0), *tail = root;

        while(cr) {
            Node *f = cr->next;
            tail->next = f;
            tail = tail->next;
            cr->next = f->next;
            cr = cr->next;
        }

        return root->next;
    }
};
