class Solution
{
public:
    int maxDistinct(string s)
    {
        vector<int> arr(26, 0);
        for (const auto &c : s)
        {
            arr[c - 'a']++;
        }

        int count = 0;
        for (const auto &a : arr)
        {
            if (a > 0)
            {
                count++;
            }
        }

        return count;
    }
};