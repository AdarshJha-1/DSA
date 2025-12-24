class Solution
{
public:
    int findSubarray(vector<int> &arr)
    {
        vector<int> prefix(arr.size(), 0);
        prefix[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }

        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (m.find(prefix[i]) != m.end())
            {
                ans += m[prefix[i]];
            }
            m[prefix[i]]++;
        }

        return ans;
    }
};