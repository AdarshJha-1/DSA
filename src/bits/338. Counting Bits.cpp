class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int t = i;
            while (t > 0)
            {
                count += (t & 1);
                t >>= 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};