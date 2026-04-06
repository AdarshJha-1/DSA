class Solution 
{
public:
    int mirrorFrequency(string s) 
    {
        unordered_map<int, bool> mp;
        int ans = 0;
        vector<int> ascii(256, 0);

        for(const auto& c : s)
        {
            ascii[c]++;
        }

        for(const auto& c : s)
        {
            char m = ' ';
            if(c >= '0' && c <= '9')
            {
                m = '9' - c + '0';
            }
            else
            {
                m = 'z' - c + 'a';
            }

            if(mp.find(c) == mp.end() && mp.find(m) == mp.end())
            {
                mp[c] = true;
                mp[m] = true;
                ans += abs(ascii[c] - ascii[m]);
            }   
        }

        return ans;
    }
};