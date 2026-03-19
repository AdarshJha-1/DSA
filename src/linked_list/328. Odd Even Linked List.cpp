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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *f = head;
        ListNode *s = head->next;
        ListNode *temp = s;

        while (s && s->next)
        {
            f->next = s->next;
            f = s->next;
            s->next = f->next;
            s = f->next;
        }

        if (f->next)
        {
            f->next = nullptr;
        }

        ListNode *tail = head;

        while (tail->next)
        {
            tail = tail->next;
        }

        tail->next = temp;
        return head;
    }
};

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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *f = head;
        ListNode *s = head->next;
        ListNode *temp = s;

        while (s && s->next)
        {
            f->next = s->next;
            f = s->next;
            s->next = f->next;
            s = f->next;
        }

        f->next = temp;
        return head;
    }
};