/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> arr;
        deque<Node*> dq;
        dq.push_back(root);
        bool flag = 0;
        while(!dq.empty()) {
            int s = dq.size();
            vector<int> temp;
            for(int i = 0; i < s; i++) {
                Node* node = dq.front();
                dq.pop_front();
                if(node->left) {
                    dq.push_back(node->left);
                }
                if(node->right) {
                    dq.push_back(node->right);
                }
                temp.push_back(node->data);
                delete node;
            }
            
            if(flag) {
                for(int i = 0; i < temp.size(); i++) {
                    arr.push_back(temp[i]);
                }
                flag = 0;
            } else {
                for(int i = temp.size() - 1; i >= 0; i--) {
                    arr.push_back(temp[i]);
                }
                flag = 1;
            }
        }
        return arr;   
    }
};
