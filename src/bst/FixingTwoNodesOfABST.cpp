/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    void ino(Node* root, vector<int> &arr) {
        if(!root) return;
        ino(root->left, arr);
        arr.push_back(root->data);
        ino(root->right, arr);
    }
    
    void sol(Node* root, vector<int> &arr, int &i) {
        if(!root) return;
        sol(root->left, arr, i);
        root->data = arr[i++];
        sol(root->right, arr, i);
    }
    void correctBST(Node* root) {
        vector<int> arr;
        ino(root, arr);
        
        int f = -1, s = -1;
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                if(f == -1) {
                    f = i;
                    s = i + 1;
                } else {
                    s = i + 1;
                }
            }
        }
        swap(arr[f], arr[s]);
        int i = 0;
        sol(root, arr, i);
    }
};
