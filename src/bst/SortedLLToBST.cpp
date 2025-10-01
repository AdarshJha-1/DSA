/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    
    TNode *ans(vector<int> &arr, int s, int e) {
        if(s > e) return nullptr;
        int m = s + (e - s + 1) / 2; 
        TNode* root = new TNode(arr[m]);
        root->left = ans(arr, s, m - 1);
        root->right = ans(arr, m + 1, e);
        return root;
    }
  
    TNode *sortedListToBST(LNode *head) {
        vector<int> arr;
        while(head) {
            arr.push_back(head->data);
            head = head->next;
        }
        return ans(arr, 0, arr.size() - 1);
    }
};
