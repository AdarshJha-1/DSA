
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
    Node* reverseLL(Node* curr, Node* prev) {
        if (!curr) return prev;
        Node* next = curr->next;
        curr->next = prev;
        return reverseLL(next, curr);
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverseLL(head1, nullptr);
        head2 = reverseLL(head2, nullptr);

        Node* curr1 = head1;
        Node* curr2 = head2;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;
        
        while (curr1 || curr2 || carry) {
            int sum = carry;
            if (curr1) {
                sum += curr1->data;
                curr1 = curr1->next;
            }
            if (curr2) {
                sum += curr2->data;
                curr2 = curr2->next;
            }
            tail->next = new Node(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
        
        Node* result = reverseLL(dummy->next, nullptr);
        return result;
    }
};
