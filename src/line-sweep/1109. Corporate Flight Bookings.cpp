// Brute force
class Solution 
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> ans(n, 0);
        for(const auto& b : bookings)
        {
            for(int i = b[0] - 1; i < b[1]; i++)
            {
                ans[i] += b[2];
            }
        }

        return ans;
    }
};

class Solution 
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> seq(n, 0);
        for(const auto& b : bookings)
        {
            seq[b[0] - 1] += b[2];
            if(b[1] < n)
            {
                seq[b[1]] -= b[2];
            }
        }


        for(const auto& v : seq)
        {
            cout << v << " ";
        }

        cout << endl;

        int currS = 0;
        for(int i = 0; i < n; i++)
        {
            currS += seq[i];
            seq[i] = currS;
        }

        return seq;
    }
};
