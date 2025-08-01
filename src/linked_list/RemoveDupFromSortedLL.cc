/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        Node* prev = head;
        Node* curr = head->next;
        while(curr) {
            if(prev->data == curr->data) {
                Node* temp = curr;
                prev->next = curr->next;
                delete temp;
                curr = prev->next;
            }else {

                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
