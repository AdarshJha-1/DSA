#include "iostream"
#include "vector"

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    vector<int> arr;
    ListNode *temp = head;
    while(temp != nullptr) {
        arr.push_back(temp->val);
        temp = temp->next; 
    }

    ListNode *temp2 = head;
    int i = arr.size() - 1;

    while(temp2 != nullptr) {
        temp2->val = arr[i];
        i--;
        temp2 = temp2->next;
    }
    return head;
}

ListNode* reverseListv1(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverseListRecursion(ListNode* curr, ListNode* prev) {
    if(curr == nullptr) {
        return;
    }

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int value : arr) {
        ListNode *newNode = new ListNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print the linked list
    ListNode *temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    head = reverseListv1(head);

    // Print the linked list
    temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}




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
    // ListNode* reverseList(ListNode* head) {
    // ListNode* curr = head;
    // ListNode* prev = nullptr;
    // ListNode* next = nullptr;
    // while(curr) {
    //     next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }
    // return prev;
    // }

    ListNode* reverseLL(ListNode* curr, ListNode* prev, ListNode* next) {
        if(!curr) return prev;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        return reverseLL(curr, prev, next);
    }

    ListNode* reverseList(ListNode* head) {
        return reverseLL(head, nullptr, nullptr);
    }
};
