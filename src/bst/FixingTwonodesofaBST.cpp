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
    void correctBST(Node* root) {
        Node *curr = root, *prev = nullptr, *f = nullptr, *s = nullptr;
        while(curr) {
            if(!curr->left) {
                if(prev) {
                    if(prev->data > curr->data) {
                        if(!f) {
                            f = prev;
                            s = curr;
                        } else {
                            s = curr;
                        }
                    }
                }
                prev = curr;
                curr = curr->right;
            } else {
                Node *temp = curr->left;
                while(temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                
                if(!temp->right) {
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    temp->right = nullptr;
                    if(prev) {
                        if(prev->data > curr->data) {
                        if(!f) {
                            f = prev;
                            s = curr;
                        } else {
                            s = curr;
                        }
                    }
                    }
                        prev = curr;
                        curr = curr->right;
                }
            }
        }
        if(f && s) {
            swap(f->data, s->data);
        }
    }
};



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
    void correctBST(Node* root) {
        Node *curr = root, *prev = nullptr, *f = nullptr, *s = nullptr;
        while(curr) {
            if(!curr->left) {
                if(prev && prev->data > curr->data) {
                    if(!f) {
                        f = prev;
                        s = curr;
                    } else {
                        s = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            } else {
                Node *temp = curr->left;
                while(temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                
                if(!temp->right) {
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    temp->right = nullptr;
                    if(prev && prev->data > curr->data) {
                        if(!f) {
                            f = prev;
                            s = curr;
                        } else {
                            s = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        if(f && s) {
            swap(f->data, s->data);
        }
    }
};
