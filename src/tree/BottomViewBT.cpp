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
  
    void lr(Node* root, int curr, int &l, int &r) {
        if(!root) return;
        l = min(l, curr);
        r = max(r, curr);
        
        lr(root->left, curr - 1, l, r);
        lr(root->right, curr + 1, l, r);
    }
    
    vector<int> bottomView(Node *root) {
        int l = 0, r = 0;
        lr(root, 0, l, r);
        vector<int> ans(r - l + 1);
        vector<int> lvls(r- l + 1, -1);
        queue<Node*> q;
        q.push(root);
        queue<int> idx;
        idx.push(-1 * l);

        int currLvl = 0;
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            int i = idx.front();
            idx.pop();
            if(currLvl > lvls[i]) {
                ans[i] = temp->data;
            }
            
            if(temp->left) {
                q.push(temp->left);
                idx.push(i - 1);
            }
             if(temp->right) {
                q.push(temp->right);
                idx.push(i + 1);
            }A
            currLvl++;
        }
        
        return ans;
    }
};
