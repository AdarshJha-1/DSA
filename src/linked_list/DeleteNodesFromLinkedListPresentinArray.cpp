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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> m;
        for (int& n : nums)
            m[n] = 1;
        ListNode *ans = new ListNode(0), *tail = ans, *temp = head;
        while (temp) {
            if (m.find(temp->val) == m.end()) {
                tail->next = temp;
                tail = tail->next;
            }
            temp = temp->next;
        }
        tail->next = nullptr;
        return ans->next;
    }
};
