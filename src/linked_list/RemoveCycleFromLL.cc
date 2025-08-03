/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
                Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) {
                break;
            }
        }

if(!fast || !fast->next) return;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        while(slow->next != fast) {
            slow = slow->next;
        }

        slow->next = nullptr;

    }
};
