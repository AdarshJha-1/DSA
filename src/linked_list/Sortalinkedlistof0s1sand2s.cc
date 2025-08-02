/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int arr[] = {0, 0, 0};
        Node* temp = head;
        while(temp) {
            arr[temp->data]++;
            temp = temp->next;
        }
        
        temp = head;
        while(arr[0]){
            temp->data = 0;
            temp = temp->next;
            arr[0]--;
        }
         while(arr[1]){
            temp->data = 1;
            temp = temp->next;
            arr[1]--;
        }
         while(arr[2]){
            temp->data = 2;
            temp = temp->next;
            arr[2]--;
        }
        
        return head;
    }
};
