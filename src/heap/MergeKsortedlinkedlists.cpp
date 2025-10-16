/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        for(Node* &n : arr) {
            while(n) {
                pq.push({n->data, n});
                n = n->next;
            }
        }
        Node *head = pq.top().second;
        pq.pop();
        Node *tail = head;
        while(!pq.empty()) {
            tail->next = pq.top().second;
            tail = tail->next;
            pq.pop();
        }
        
        tail->next = nullptr;
        return head;
    }
};
