// User function Template for C++

class Solution
{
public:
    void build(int arr[], int l, int r, int i, vector<int> &segT)
    {
        if (l > r)
        {
            return;
        }
        if (l == r)
        {
            segT[i] = arr[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(arr, l, m, 2 * i + 1, segT);
        build(arr, m + 1, r, 2 * i + 2, segT);
        segT[i] = segT[2 * i + 1] + segT[2 * i + 2];
        return;
    }

    int query(int l, int r, int rl, int rr, int i, vector<int> &segT)
    {
        if (l > r || rl > r || rr < l)
        {
            return 0;
        }
        if (l >= rl && r <= rr)
        {
            return segT[i];
        }
        int m = l + (r - l) / 2;
        return query(l, m, rl, rr, 2 * i + 1, segT) + query(m + 1, r, rl, rr, 2 * i + 2, segT);
    }

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> segT(4 * n, 0);
        build(arr, 0, n - 1, 0, segT);
        vector<int> ans;
        for (int i = 0; i < 2 * q; i += 2)
        {
            ans.push_back(query(0, n - 1, queries[i] - 1, queries[i + 1] - 1, 0, segT));
        }

        return ans;
    }
};

/* [0, 1, 2, 3]
arr = [1, 2, 3, 4]
[0, 1, 2, 3, 4, 5, 6]
segT = [10, 3, 7, 1, 2, 3, 4]
*/