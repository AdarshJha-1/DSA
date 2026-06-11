class Solution 
{
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> m;
        for(const auto& c : s)
        {
            m[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto const &[k, v] : m)
        {
            pq.push({v, k});
        }

        string ans = "";

        while(!pq.empty() && pq.size() != 1)
        {
            auto [f1, c1] = pq.top();
            pq.pop();
            auto [f2, c2] = pq.top();
            pq.pop();

            ans.push_back(c1);
            f1--;
            ans.push_back(c2);
            f2--;

            if(f1 != 0)
            {
                pq.push({f1, c1});
            }
            if(f2 != 0)
            {
                pq.push({f2, c2});
            }
        }
        if(!pq.empty() && pq.size() == 1)
        {
            auto [f, c] = pq.top();
            pq.pop();
            if(f == 2 && ans[0] != c && ans[ans.size() - 1] != c)
            {
                ans.insert(0, 1, c);
                ans.push_back(c);
            }
            else if(f == 1)
            {
                if(ans[0] != c)
                {
                    ans.insert(0, 1, c);
                }
                else if(ans[ans.size() - 1] != c)
                {
                    ans.push_back(c);
                }
                else
                {
                    return "";
                }
            }
            else
            {
                return "";
            }
        }
        return ans;
    }
};
