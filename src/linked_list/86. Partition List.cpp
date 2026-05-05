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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *sh = new ListNode(0), *st = sh;
        ListNode *bh = new ListNode(0), *bt = bh;

        while (head)
        {
            if (head->val < x)
            {
                st->next = head;
                st = st->next;
            }
            else
            {
                bt->next = head;
                bt = bt->next;
            }
            head = head->next;
        }
        bt->next = nullptr;

        st->next = bh->next;

        return sh->next;
    }
};