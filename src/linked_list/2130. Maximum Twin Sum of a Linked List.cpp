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
    int pairSum(ListNode* head) 
    {
        ListNode* temp = head;
        int n = 0;
        while(temp)
        {
            n += 2;
            temp = temp->next->next;
        }

        stack<int> st;
        temp = head;
        for(int i = 0; i < n / 2; i++)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        int ans = 0;
        for(int i = n / 2; i < n; i++)
        {
            ans = max(ans, st.top() + temp->val);
            st.pop();
            temp = temp->next;
        }

        return ans;
    }
};
