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
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        /*
            if (list1 != nullptr) {
                while (list1) {
                    tail->next = list1;
                    tail = tail->next;
                    list1 = list1->next;
                }
            }

            if (list2 != nullptr) {
                while (list2) {
                    tail->next = list2;
                    tail = tail->next;
                    list2 = list2->next;
                }
            }
        */
        // or

        // if list1 is not pointing to nullptr than tail->next = list1 if not than tail->next = list2;
        tail->next = list1 ? list1 : list2;

        return dummy->next;
    }
};



// Recursion Version
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

    void sol(ListNode*& tail, ListNode*& n1, ListNode*& n2) {
        if(!n1 || !n2) return;
        if(n1->val < n2->val) {
            tail->next = n1;
            tail = tail->next;
            n1 = n1->next;
        } else {
            tail->next = n2;
            tail = tail->next;
            n2 = n2->next;
        }
        sol(tail, n1, n2);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        sol(tail, list1, list2);

        tail->next = list1 ? list1 : list2;
        return dummy->next;
    }
};

