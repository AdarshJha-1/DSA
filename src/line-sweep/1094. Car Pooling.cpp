class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        map<int, int> m;
        for(const auto& t : trips)
        {
            if(t[0] > capacity)
            {
                return false;
            }
            m[t[1]] += t[0];
            m[t[2]] += -t[0];
        }    

        int maxP = 0;
        int currP = 0;
        for(auto const& [k, v] : m)
        {
            currP += v;
            maxP = max(maxP, currP);

            if(maxP > capacity)
            {
                return false;
            } 
        }

        return true;
    }
};
