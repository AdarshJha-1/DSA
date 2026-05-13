class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        vector<pair<int, int>> seq;
        for(const auto& log : logs)
        {
            seq.push_back({log[0], 1});
            seq.push_back({log[1], -1});
        }

        sort(seq.begin(), seq.end());

        int ans = 2050;
        int maxP = 0;

        int currP = 0;
        for(const auto& s : seq)
        {
            currP += s.second;
            if(currP > maxP)
            {
                ans = s.first;
                maxP = currP;
            }
        }

        return ans;
    }
};
