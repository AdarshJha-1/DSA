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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }

        n = (n / 2) + 1;
        temp = head;
        while(n > 1) {
            temp = temp->next;
            n--;
        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(temp) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        ListNode* l = head;
        temp = nullptr;

        ListNode* r = prev;
        ListNode* temp2 = nullptr;

        while(r->next) {
            temp = l->next;
            l->next = r;
            l = temp;
            temp2 = r->next;
            r->next = l;
            r = temp2;
        }
    }
};
