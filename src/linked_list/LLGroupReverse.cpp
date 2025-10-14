/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
       Node *f = new Node(0);
       f->next = head;
       head = f;
       while(f->next) {
           int x = k;
           Node *s = f->next;
           Node *p = f, *c = s, *n = nullptr;
           while(x-- && c) {
               n = c->next;
               c->next = p;
               p = c;
               c = n;
           }
           f->next = p;
           s->next = c;
           f = s;
       }
       
       head = head->next;
       return head;
    }
};
