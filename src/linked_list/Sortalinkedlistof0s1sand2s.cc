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
    Node* segregateM1(Node* head) {
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

    Node* segregateM2(Node* head) {
        if(!head) return head;
        Node* temp = hrad;
        Node* head0 = nullptr;
        Node* temp0= nullptr;

        Node* head1 = nullptr;
        Node* temp1 = nullptr;

        Node* head2 = nullptr;
        Node* temp2 = nullptr;

        while(temp) {
            if(temp->data == 0) {
                if(!head0) {
                    head0 = temp;
                    temp0 = temp;
                } else {
                    temp0->next = temp;
                    temp0 = temp0->next;
                }
            } else if(temp->data == 1) {
                if(!head1) {
                    head1 = temp;
                    temp1 = temp;
                } else {
                    temp1->next = temp;
                    temp1 = temp1->next;
                }
            }else {
                if(!head2) {
                    head2 = temp;
                    temp2 = temp;
                } else {
                    temp2->next = temp;
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }

        temp0->next = head1;
        temp1->next = head2;
        temp2->next = nullptr;
        return head0;
    }
};
