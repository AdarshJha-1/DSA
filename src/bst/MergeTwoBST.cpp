/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void ino(Node* root, vector<int> &arr) {
        if(!root) return;
        ino(root->left, arr);
        arr.push_back(root->data);
        ino(root->right, arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans, a1, a2;
        ino(root1, a1);
        ino(root2, a2);
        
        int i = 0, j = 0;
        while(i < a1.size() && j < a2.size()) {
            if(a1[i] < a2[j]) {
                ans.push_back(a1[i++]);
            } else {
                ans.push_back(a2[j++]);
            }
        }
        
        while(i != a1.size()) {
            ans.push_back(a1[i++]);
        }
        
        while(j != a2.size()) {
            ans.push_back(a2[j++]);
        }
        
        return ans;
    }
};


/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void ino(Node* root, vector<int> &arr) {
        if(!root) return;
        ino(root->left, arr);
        arr.push_back(root->data);
        ino(root->right, arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        ino(root1, ans);
        ino(root2, ans);
        
       sort(ans.begin(), ans.end());
        return ans;
    }
};




/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        stack<Node*> s1, s2;
        while(root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        
        while(root2) {
            s2.push(root2);
            root2 = root2->left;
        }
        
        
        while(!s1.empty() && !s2.empty()) {
            if(s1.top()->data < s2.top()->data) {
                ans.push_back(s1.top()->data);
                Node* temp = s1.top()->right;
                s1.pop();
                while(temp){
                    s1.push(temp);
                    temp = temp->left;
                }
            } else {
                ans.push_back(s2.top()->data);
                Node* temp = s2.top()->right;
                s2.pop();
                while(temp){
                    s2.push(temp);
                    temp = temp->left;
                }
            }
        }
        
        while(!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            temp = temp->right;
            while(temp) {
                s1.push(temp);
                temp = temp->left;
            }
        }
        
        while(!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);
            temp = temp->right;
            while(temp) {
                s2.push(temp);
                temp = temp->left;
            }
        }
        
        return ans;
    }
};
