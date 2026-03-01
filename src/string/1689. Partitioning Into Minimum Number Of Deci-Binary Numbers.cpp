class Solution
{
public:
    int minPartitions(string n)
    {
        int ans = 0;
        for (const auto &d : n)
        {
            ans = max(ans, d - '0');
        }

        return ans;
    }
};

class Solution
{
public:
    int minPartitions(string n)
    {
        return *max_element(n.begin(), n.end());
    }
};
