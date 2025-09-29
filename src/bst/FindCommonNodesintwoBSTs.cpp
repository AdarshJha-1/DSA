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


class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int> ans;
        stack<Node*> s1, s2;
        while(r1) {
            s1.push(r1);
            r1 = r1->left;
        }
        while(r2) {
            s2.push(r2);
            r2 = r2->left;
        }
        
        while(!s1.empty() && !s2.empty()) {
            Node* t1 = s1.top();
            Node* t2 = s2.top();
            if(t1->data == t2->data) {
                ans.push_back(t1->data);
                t1 = t1->right;
                s1.pop();
                t2 = t2->right;
                s2.pop();
                while(t1) {
                    s1.push(t1);
                    t1 = t1->left;
                }
                while(t2) {
                    s2.push(t2);
                    t2 = t2->left;
                }
            } else if(t1->data < t2->data) {
                 t1 = t1->right;
                s1.pop();
                    while(t1) {
                    s1.push(t1);
                    t1 = t1->left;
                }
            } else {
                 t2 = t2->right;
                s2.pop();
                while(t2) {
                    s2.push(t2);
                    t2 = t2->left;
                }
            }
        }
        
        return ans;
    }
};
