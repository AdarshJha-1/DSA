class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // brute force
        int n = arr[arr.size() - 1];
        vector<int> present(n + 1, 0);
        for (const auto &a : arr)
        {
            present[a]++;
        }

        int notP = 0;
        int i = 1;
        for (; i <= n; i++)
        {
            if (present[i] == 0)
            {
                notP++;
            }

            if (notP == k)
            {
                return i;
            }
        }
        return i + (k - notP - 1);
    }
};