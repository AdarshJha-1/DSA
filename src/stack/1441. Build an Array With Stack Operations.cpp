class Solution 
{
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        unordered_map<int, bool> m;
        for(const auto &t : target)
        {
            m[t] = true;
        }   

        vector<string> ans;
        for(int i = 1; i <= target[target.size() - 1]; i++)
        {
            ans.push_back("Push");
            if(m.count(i) == 0)
            {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
