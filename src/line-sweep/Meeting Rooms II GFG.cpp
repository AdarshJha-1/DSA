
class Solution 
{
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) 
    {
        int n = start.size();
        vector<pair<int, int>> seq;
        for(int i = 0; i < n; i++)
        {
            seq.push_back({start[i], 1});
            seq.push_back({end[i], -1});
        }
        
        sort(seq.begin(), seq.end());
        
        int maxM = 0;
        
        int currM = 0;
        
        for(const auto& s : seq)
        {
            currM += s.second;
            
            if(currM > maxM)
            {
                maxM = currM;
            }
        }
        
        return maxM;
    }
};
