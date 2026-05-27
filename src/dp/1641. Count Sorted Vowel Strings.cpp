class Solution 
{
public:

    vector<vector<int>> dp;

    int sol(vector<char>& vowels, int n, int i, int currLen)
    {
        if(currLen == n)
        {
            return 1;
        }
        if(i >= 5)
        {
            return 0;
        }
        if(dp[i][currLen] != -1)
        {
            return dp[i][currLen];
        }
        int ans = 0;
        // skip
        ans += sol(vowels, n, i + 1, currLen);
        // take
        if(i <= 4)
        {
            ans += sol(vowels, n, i, currLen + 1);
        }
        return dp[i][currLen] = ans;
    }

    int countVowelStrings(int n) 
    {
        dp.resize(5, vector<int>(n + 1, -1));
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return sol(vowels, n, 0, 0);
    }
};


// without dp
class Solution 
{
public:

    int sol(vector<char>& vowels, int n, int i, int currLen)
    {
        if(currLen == n)
        {
            return 1;
        }
        if(i >= 5)
        {
            return 0;
        }
        int ans = 0;
        // skip
        ans += sol(vowels, n, i + 1, currLen);
        // take
        if(i <= 4)
        {
            ans += sol(vowels, n, i, currLen + 1);
        }
        return ans;
    }

    int countVowelStrings(int n) 
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return sol(vowels, n, 0, 0);
    }
};
