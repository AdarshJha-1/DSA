/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
        // new LL
        unordered_map<Node*, int> m1;
        unordered_map<int, Node*> m2;
        unordered_map<int, int> random;
        
        Node *temp = head;
        Node *root = new Node(0);
        Node *tail = root;
        
        int i = 1;
        
        while(temp) {
            tail->next = new Node(temp->data);
            tail = tail->next;
            m1[temp] = i;
            m2[i++] = tail;
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            int i = m1[temp];
            int j = -1;
            if(m1.find(temp->random) != m1.end()) {
                j = m1[temp->random];
            }
            
            random[i] = j;
            temp = temp->next;
        }
        
        for(auto &it : random) {
            if(it.second == -1) {
                m2[it.first]->random = nullptr;
            } else {
                m2[it.first]->random = m2[it.second];
            }
        }
        
        return root->next;
    }
};
