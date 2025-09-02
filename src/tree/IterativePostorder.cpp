// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        vector<int> ans;
        stack<Node*> st;
        st.push(node);
        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        
        int s = 0, e = ans.size() - 1;
        while(s <= e) {
            swap(ans[s], ans[e]);
            s++;
            e--;
        }
        
        return ans;
    }
};
