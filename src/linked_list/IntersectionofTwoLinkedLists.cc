/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        int count1 = 0;
        while (temp1) {
            count1++;
            temp1 = temp1->next;
        }

        ListNode* temp2 = headB;
        int count2 = 0;
        while (temp2) {
            count2++;
            temp2 = temp2->next;
        }

        int ahead = 0;
        if (count1 > count2) {
            ahead = count1 - count2;
            temp1 = headA;
            temp2 = headB;
            while (ahead--) {
                temp1 = temp1->next;
            }
        } else {
            ahead = count2 - count1;
            temp2 = headB;
            temp1 = headA;
            while (ahead--) {
                temp2 = temp2->next;
            }
        }

        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};
