class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        int ans = INT_MAX;
        int n = words.size();
        if (words[startIndex] == target)
        {
            return 0;
        }
        int i = startIndex + 1;
        int c = 0;
        while ((i % n) != startIndex)
        {
            c++;
            if (words[i % n] == target)
            {
                ans = min(ans, c);
            }
            i++;
        }
        i = startIndex - 1;
        if (i < 0)
        {
            i = n - 1;
        }
        c = 0;
        while ((i % n) != startIndex)
        {
            c++;
            if (words[i % n] == target)
            {
                ans = min(ans, c);
            }
            i--;
            if (i < 0)
            {
                i = n - 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};