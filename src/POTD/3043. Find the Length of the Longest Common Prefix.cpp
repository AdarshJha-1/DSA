class Solution 
{
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        int ans = 0;
        unordered_map<string, int> m;
        for(const auto& a : arr1)
        {
            string s = to_string(a);
            string temp = "";
            for(const auto& c : s)
            {
                temp += c;
                m[temp]++;
            }
        }

        for(const auto& a : arr2)
        {
            string s = to_string(a);
            string temp = "";
            for(const auto& c : s)
            {
                temp += c;
                if(m.count(temp) != 0)
                {
                    m[temp]++;
                    ans = max(ans, (int)temp.size());
                }
            }
        }

        return ans;
    }
};
