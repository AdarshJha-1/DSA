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
  
    Node *merge(Node *h1, Node *h2) {
        Node *head = new Node(0);
        Node *tail = head;
        while(h1 && h2) {
            if(h1->data <= h2->data) {
                tail->next = h1;
                h1 = h1->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                tail->next = h2;
                h2 = h2->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        if(h1) {
            tail->next = h1;
        }
        if(h2) {
            tail->next = h2;
        }
        return head->next;
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        Node *root = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            root = merge(root, arr[i]);
        }
        return root;
    }
};



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
    
    Node *merge(Node *h1, Node *h2) {
        Node *head = new Node(0);
        Node *tail = head;
        while(h1 && h2) {
            if(h1->data <= h2->data) {
                tail->next = h1;
                h1 = h1->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                tail->next = h2;
                h2 = h2->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        if(h1) {
            tail->next = h1;
        }
        if(h2) {
            tail->next = h2;
        }
        return head->next;
    }

    
    void mergeSort(vector<Node*>& arr, int l, int r) {
        if(l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        arr[l] = merge(arr[l], arr[m + 1]);
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        mergeSort(arr, 0, arr.size()- 1);
        return arr[0];
    }
};
