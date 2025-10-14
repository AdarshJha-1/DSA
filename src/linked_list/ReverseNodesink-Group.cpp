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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int lenLL = 0;
        ListNode *temp = head;
        while(temp) {
            lenLL++;
            temp = temp->next;
        }
        int times = lenLL / k;
        ListNode *d = new ListNode(0);
        d->next = head;
        head = d;
        ListNode *f = head;
        while(times--) {
            int x = k;
            ListNode *s = f->next, *c = s, *p = f, *n = nullptr;
            while(x-- && c) {
                n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            f->next = p;
            s->next = c;
            f = s;
        }
        return head->next;
    }
};
