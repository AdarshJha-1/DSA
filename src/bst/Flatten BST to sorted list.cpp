/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    void ind(Node *root, vector<int> &arr)
    {
        if (!root)
            return;
        ind(root->left, arr);
        arr.push_back(root->data);
        ind(root->right, arr);
    }

    // Brute force
    Node *flattenBST(Node *root)
    {
        vector<int> temp;
        ind(root, temp);
        root->data = temp[0];
        Node *tail = root;
        root->left = nullptr;
        for (int i = 1; i < temp.size(); i++)
        {
            tail->right = new Node(temp[i]);
            tail = tail->right;
        }
        return root;
    }
};

/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }
        Node *head = flattenBST(root->left);
        root->left = nullptr;
        if (!head)
        {
            head = root;
        }
        else
        {
            Node *temp = head;
            while (temp && temp->right)
            {
                temp = temp->right;
            }
            temp->right = root;
        }

        root->right = flattenBST(root->right);
        return head;
    }
};

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution
{
public:
    Node *mergeToSortedList(Node *head1, Node *head2)
    {
        if (!head1)
        {
            return head2;
        }
        if (!head2)
        {
            return head1;
        }
        Node *result;
        if (head1->data < head2->data)
        {
            result = head1;
            result->bottom = mergeToSortedList(head1->bottom, head2);
        }
        else
        {
            result = head2;
            result->bottom = mergeToSortedList(head1, head2->bottom);
        }
        return result;
    }

    Node *flatten(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }
        Node *head = flatten(root->next);
        return mergeToSortedList(root, head);
    }
};