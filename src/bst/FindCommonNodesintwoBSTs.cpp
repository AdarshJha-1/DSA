class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    void sol(Node* root, unordered_map<int, int> &m) {
        if(!root) return;
        sol(root->left, m);
        m[root->data]++;
        sol(root->right, m);
    }
    
    vector<int> findCommon(Node *r1, Node *r2) {
        unordered_map<int, int> m;
        sol(r1, m);
        sol(r2, m);
        vector<int> ans;
        for(auto &it : m) {
            if(it.second == 2) {
                ans.push_back(it.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
