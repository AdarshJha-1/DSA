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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1 && right == 1) return head;
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode *f = d, *s = d->next;
        int i = left;
        while(i != 1) {
            f = s;
            s = s->next;
            i--;
        }
        i = (right - left) + 1;
        ListNode *c = s, *p = nullptr, *n = nullptr;
        while(i--) {  
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        f->next = p;
        s->next = c;
        return d->next;
    }
};
