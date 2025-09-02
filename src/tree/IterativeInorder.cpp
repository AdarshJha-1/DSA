// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        unordered_map<Node*, bool> m;
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();
            if(m.find(temp) == m.end()) {
                m[temp] = 1;
                if(temp->right) st.push(temp->right);
                st.push(temp);
                if(temp->left) st.push(temp->left);
            } else {
                ans.push_back(temp->data);
            }
        }
        
        return ans;
    }
};
