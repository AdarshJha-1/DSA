class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int open = 0;
        for (const auto &p : s)
        {
            if (p == '(')
            {
                open++;
                ans = max(ans, open);
            }
            else if (p == ')')
            {
                open--;
            }
        }

        return ans;
    }
};