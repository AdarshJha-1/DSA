/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* curr = head;
        Node *root = new Node(0), *tail = root;

        while (curr) {
            if (curr->next && !curr->child) {
                tail->next = curr;
                curr->prev = tail;
                tail = tail->next;
                curr = curr->next;
            } else if (curr->child && !curr->next) {
                tail->next = curr;
                curr->prev = tail;
                tail = tail->next;
                Node* t = curr->child;
                curr->child = nullptr;
                curr = t;
            } else if (curr->next && curr->child) {
                st.push(curr->next);
                tail->next = curr;
                curr->prev = tail;
                tail = tail->next;
                Node* t = curr->child;
                curr->child = nullptr;
                curr = t;
            } else {
                tail->next = curr;
                curr->prev = tail;
                tail = tail->next;
                curr = curr->next;
            }
        }

        while (!st.empty()) {
            Node* t = st.top();
            st.pop();
            tail->next = t;
            t->prev = tail;
            while (tail->next) {
                tail = tail->next;
            }
        }

        return root->next;
    }
};
