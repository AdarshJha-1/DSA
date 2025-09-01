/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    void lr(Node* root, int curr, int &l, int &r) {
        if(!root) return;
        l = min(curr, l);
        r = max(curr, r);
        
        lr(root->left, curr - 1, l, r);
        lr(root->right, curr + 1, l, r);
    }
    vector<int> topView(Node *root) {
        int l = 0, r = 0;
        lr(root, 0, l, r);
        vector<int> ans(r - l + 1);
        vector<int> filled(r - l + 1, 0);
        queue<Node*> q;
        queue<int> index;
        
        q.push(root);
        index.push(-1 * l);
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            
            if(!filled[pos]) {
                filled[pos] = 1;
                ans[pos] = temp->data;
            }
            
            if(temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            
            if(temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }
        return ans;
    }
};


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    void lr(Node* root, int curr, int &l, int &r) {
        if(!root) return;
        l = min(curr, l);
        r = max(curr, r);
        
        lr(root->left, curr - 1, l, r);
        lr(root->right, curr + 1, l, r);
    }
    
    void find(Node* root, vector<int>& ans, vector<int>& lvl, int curLvl, int pos) {
        if(!root) return;
        if(curLvl < lvl[pos]) {
            ans[pos] = root->data;
            lvl[pos] = curLvl;
        }
        find(root->left, ans, lvl, curLvl + 1, pos - 1);
        find(root->right, ans, lvl, curLvl + 1, pos + 1);

    }
    
    vector<int> topView(Node *root) {
        int l = 0, r = 0;
        lr(root, 0, l, r);
        vector<int> ans(r - l + 1);
        vector<int> filled(r - l + 1, INT_MAX);
        
        find(root, ans, filled, 0, - 1 * l);
        // queue<Node*> q; 
        // queue<int> index;
        
        // q.push(root);
        // index.push(-1 * l);
        // while(!q.empty()) {
        //     Node* temp = q.front();
        //     q.pop();
        //     int pos = index.front();
        //     index.pop();
            
        //     if(!filled[pos]) {
        //         filled[pos] = 1;
        //         ans[pos] = temp->data;
        //     }
            
        //     if(temp->left) {
        //         q.push(temp->left);
        //         index.push(pos - 1);
        //     }
            
        //     if(temp->right) {
        //         q.push(temp->right);
        //         index.push(pos + 1);
        //     }
        // }
        return ans;
    }
};
