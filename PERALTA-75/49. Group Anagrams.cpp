class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> m;
        int idx = 0;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (m.find(temp) == m.end())
            {
                m[temp] = idx;
                idx++;
                ans.push_back({str});
            }
            else
            {
                ans[m[temp]].push_back(str);
            }
        }
        return ans;
    }
};