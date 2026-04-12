class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> pc(n, 0); // track parent count for a node
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                pc[leftChild[i]]++;
            }
            if (rightChild[i] != -1)
            {
                pc[rightChild[i]]++;
            }
        }

        int root = -1;
        int rootC = 0;
        for (int i = 0; i < n; i++)
        {
            if (pc[i] == 0)
            {
                root = i;
                rootC++;
            }
        }
        if (rootC > 1 || rootC == 0)
        {
            return false;
        }
        int nodeC = 0;
        queue<int> q;
        q.push(root);
        vector<bool> seen(n, false);
        seen[root] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            nodeC++;
            if (leftChild[node] != -1)
            {
                if (seen[leftChild[node]])
                {
                    return false;
                }
                seen[leftChild[node]] = true;
                q.push(leftChild[node]);
            }
            if (rightChild[node] != -1)
            {
                if (seen[rightChild[node]])
                {
                    return false;
                }
                seen[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }
        return nodeC == n;
    }
};