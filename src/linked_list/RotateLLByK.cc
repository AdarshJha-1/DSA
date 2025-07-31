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
#include <utility>
#include <vector>
class Solution {
public:

    void roatet(vector<int> &arr, int s, int e) {
        while (s <= e) {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }

    ListNode* rotateRightBF(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }


        // roatet array 
        int n = arr.size();
        k = k % n;

        int last = n - k;
        roatet(arr, 0, last - 1);
        roatet(arr, last, arr.size() -1 );
        roatet(arr, 0, arr.size() -1 );

        
        temp = head;
        int i = 0;
        while(temp && i < arr.size()) {
            temp->val = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            n++;
            temp = temp->next;
        }

        temp->next = head;
        
        k = k % n;
        int last = n - k - 1;
        int i= 0;
        temp = head;
        while(i < last) {
            temp = temp->next;
            i++;
        }

        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};


