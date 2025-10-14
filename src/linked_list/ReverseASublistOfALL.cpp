// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        Node *d = new Node(0);
        d->next = head;
        head = d;
        Node *f = head;
        int x = a;
        while(x != 1) {
            f = f->next;
            x--;
        }
        int k = b - a  + 1;
        Node *s = f->next, *c = s, *p = f, *n = nullptr;
        while(k--) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        f->next = p;
        s->next = c;
        return head->next;
    }
};
