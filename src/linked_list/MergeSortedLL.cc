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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;
        ListNode* ans = nullptr;
        if (list1->val < list2->val) {
            ans = list1;
            list1 = list1->next;
        } else {
            ans = list2;
            list2 = list2->next;
        }
        ListNode* temp = ans;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }

        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return ans;
    }
};
