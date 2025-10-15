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
        Node *c1 = head, *chead = new Node(0), *c2 = chead;
        while(c1) {
            c2->next = new Node(c1->data);
            c2 = c2->next;
            c1 = c1->next;
        }
        
        c1 = head, c2 = chead->next;
        Node *f1, *f2;
        while(c1) {
            f1 = c1->next, f2 = c2->next;
            c1->next = c2;
            c2->next = f1;
            c1 = f1;
            c2 = f2;
        }
        
        c1 = head;
        while(c1) {
            c2 = c1->next;
            if(c1->random) {
                c2->random = c1->random->next;
            } else {
                c2->random = nullptr;
            }
            c1 = c2->next;
        }
        
        c1 = head;
        Node *tail = chead;
        while(c1) {
            c2 = c1->next;
            Node *f = c2->next;
            tail->next = c2;
            tail = tail->next;
            c1->next = f;
            c1 = f;
        }
        
        return chead->next;
    }
};
