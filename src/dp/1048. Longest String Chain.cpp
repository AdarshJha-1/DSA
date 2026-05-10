class Solution {
public:

    vector<vector<int>> dp;

    bool isValid(string &a, string &b)
    {
        if(b.size() != a.size() + 1)
        {
            return false;
        }

        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }
            else 
            {
                j++;
            }
        }
        return i == a.size();
    }

    int sol(vector<string>& words, int n, int i, int p)
    {
        if(i >= n)
        {
            return 0;
        }

        if(p != -1 && dp[i][p] != -1)
        {
            return dp[i][p];
        }
        int skip = sol(words, n, i + 1, p);
        int take = 0;
        if(p == -1 || isValid(words[p], words[i]))
        {  
            take = sol(words, n, i + 1, i) + 1;
        }

        if(p != -1)
        {
            dp[i][p] = max(skip, take);
        }
        return max(skip, take);
    }

    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), 
            [](const string &a, const string &b)
            {
                return a.length() < b.length();    
            }
        );

        int n = words.size();
        dp.resize(1001, vector<int>(1001, -1));
        return sol(words, n, 0, -1);
    }
};



class Solution {
public:


    bool isValid(string &a, string &b)
    {
        if(b.size() != a.size() + 1)
        {
            return false;
        }

        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }
            else 
            {
                j++;
            }
        }
        return i == a.size();
    }
 
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), 
            [](const string &a, const string &b)
            {
                return a.length() < b.length();    
            }
        );

        int n = words.size();
        vector<int> dp(n, 1);

        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(isValid(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
