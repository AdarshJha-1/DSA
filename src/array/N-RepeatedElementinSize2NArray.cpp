class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        for (const auto& n : nums)
        {
            m[n]++;
        }
        int ans = INT_MIN;
        int freq = INT_MIN;
        for(const auto& it : m)
        {
            if(it.second > freq)
            {
                ans = it.first;
                freq = it.second;
            }
        }
        return ans;
    }
};
