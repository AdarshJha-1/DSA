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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        for (auto &l : lists)
        {
            if (l)
            {
                pq.push({l->val, l});
            }
        }

        while (!pq.empty())
        {
            auto [val, node] = pq.top();
            pq.pop();
            if (!head)
            {
                head = node;
                tail = head;
            }
            else
            {
                tail->next = node;
                tail = tail->next;
            }
            if (node->next)
            {
                pq.push({node->next->val, node->next});
            }
        }

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
    struct CompareNodes
    {
        bool operator()(const ListNode *a, const ListNode *b) const
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, CompareNodes> pq;
        for (auto &l : lists)
        {
            if (l)
            {
                pq.push(l);
            }
        }

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
            {
                pq.push(node->next);
            }
        }

        return head->next;
    }
};