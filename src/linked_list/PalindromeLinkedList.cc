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
#include <vector>
class Solution {
public:

    ListNode* reversLL(ListNode* head) {
        ListNode *b = nullptr;
        ListNode *c = head;
        ListNode *f = nullptr;

        while(c) {
            f = c->next;
            c->next = b;
            b = c;
            c = f;
        }

        return b;
    }


    bool compareLL(ListNode* f, ListNode* s) {
        while(f) {
            if(f->val != s->val) {
                return false;
            }
            f = f->next;
            s = s->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        int count = 0;
        ListNode* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }

        count /= 2;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;

        curr = reversLL(curr);
        return compareLL(head, curr);
        
    }
};
