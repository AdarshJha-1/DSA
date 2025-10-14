/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        long long n1 = 0, n2 = 0;
        while(head1) {
            n1 = n1 * 10 + head1->data;
            head1 = head1->next;
        }
        
        while(head2) {
            n2 = n2 * 10 + head2->data;
            head2 = head2->next;
        }
        
        long long sum = n1 + n2;
        Node* h = new Node(sum % 10);
        sum /= 10;
        while(sum) {
            Node *temp = new Node(sum%10);
            sum /= 10;
            temp->next = h;
            h = temp;
        }

        return h;
    }
};


/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* reverseLL(Node* h) {
        Node* c = h, *p = nullptr, *n = nullptr;
        while(c) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        return p;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverseLL(head1);
        head2 = reverseLL(head2);
        
        int c = 0;
        Node* ans = nullptr, *temp = nullptr;
        
        while(head1 && head2) {
            int sum = head1->data + head2->data + c;
            if(!ans) {
                ans = new Node(sum%10);
                temp = ans;
                c = sum / 10;
            } else {
                temp->next = new Node(sum%10);
                c = sum / 10;
                temp = temp->next;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1)  {
            int sum = head1->data + c;
            temp->next = new Node(sum%10);
            c = sum / 10;
            temp = temp->next;
            head1 = head1->next;
        }
        
         while(head2)  {
            int sum = head2->data + c;
            temp->next = new Node(sum%10);
            c = sum / 10;
            temp = temp->next;
            head2 = head2->next;
        }
        
        while(c) {
            temp->next = new Node(c%10);
            c /= 10;
        }
        ans = reverseLL(ans);
        while(ans->data == 0) {
            ans = ans->next;
        }
        return ans;
    }
};
