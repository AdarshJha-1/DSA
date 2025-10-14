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
