/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n > 30) return head;
        if(!head->next) return nullptr;
        if(!head->next->next) {
            if(n == 1) {
                ListNode* temp = head->next;
                delete temp;
                head->next = nullptr;
                return head;
            }
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int totalNodes = 0;
        ListNode* temp = head;
        while(temp) {
            totalNodes++;
            temp = temp->next;
        }

        int haveToGoTill = totalNodes - n;
        int i = 1;
        temp = head;
        while(i < haveToGoTill) {
            temp = temp->next;
            i++;
        }
        ListNode* dNode = temp->next;
        if(n == 1) {
        temp->next = nullptr;
        } else {
        temp->next = dNode->next;
        }
        delete dNode;
        return head;
    }
};
