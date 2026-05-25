class Solution
{
public:
    unordered_map<string, pair<int, int>> mp;
    vector<vector<vector<int>>> dp;

    int sol(vector<string> &strs, int m, int n, int cm, int cn, int idx)
    {
        if (idx >= strs.size())
        {
            return 0;
        }
        if (dp[idx][cm][cn] != -1)
        {
            return dp[idx][cm][cn];
        }
        int skip = sol(strs, m, n, cm, cn, idx + 1);
        int take = 0;
        const auto &[c0, c1] = mp[strs[idx]];
        if (cm + c0 <= m && cn + c1 <= n)
        {
            take = sol(strs, m, n, cm + c0, cn + c1, idx + 1) + 1;
        }

        return dp[idx][cm][cn] = max(take, skip);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        dp.resize(601, vector<vector<int>>(101, vector<int>(101, -1)));
        for (const auto &str : strs)
        {
            int c0 = 0;
            int c1 = 0;
            for (const auto &c : str)
            {
                c0 += c == '0';
                c1 += c == '1';
            }
            mp[str] = {c0, c1};
        }

        return sol(strs, m, n, 0, 0, 0);
    }
};

class Solution
{
public:
    unordered_map<string, pair<int, int>> mp;
    vector<vector<vector<int>>> dp;

    int sol(vector<string> &strs, int m, int n, int cm, int cn, int idx)
    {
        if (idx >= strs.size())
        {
            return 0;
        }
        if (dp[idx][cm][cn] != -1)
        {
            return dp[idx][cm][cn];
        }
        int skip = sol(strs, m, n, cm, cn, idx + 1);
        int take = 0;
        const auto &[c0, c1] = mp[strs[idx]];
        if (cm + c0 <= m && cn + c1 <= n)
        {
            take = sol(strs, m, n, cm + c0, cn + c1, idx + 1) + 1;
        }

        return dp[idx][cm][cn] = max(take, skip);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        dp.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for (const auto &str : strs)
        {
            int c0 = 0;
            int c1 = 0;
            for (const auto &c : str)
            {
                c0 += c == '0';
                c1 += c == '1';
            }
            mp[str] = {c0, c1};
        }

        return sol(strs, m, n, 0, 0, 0);
    }
};

class Solution
{
public:
    vector<pair<int, int>> cnt;
    vector<vector<vector<int>>> dp;

    int sol(vector<string> &strs, int m, int n, int cm, int cn, int idx)
    {
        if (idx >= strs.size())
        {
            return 0;
        }
        if (dp[idx][cm][cn] != -1)
        {
            return dp[idx][cm][cn];
        }
        int skip = sol(strs, m, n, cm, cn, idx + 1);
        int take = 0;
        const auto &[c0, c1] = cnt[idx];
        if (cm + c0 <= m && cn + c1 <= n)
        {
            take = sol(strs, m, n, cm + c0, cn + c1, idx + 1) + 1;
        }

        return dp[idx][cm][cn] = max(take, skip);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        cnt.resize(strs.size());
        dp.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for (int i = 0; i < strs.size(); i++)
        {
            int c0 = 0;
            int c1 = 0;
            for (const auto &c : strs[i])
            {
                c0 += c == '0';
                c1 += c == '1';
            }
            cnt[i] = {c0, c1};
        }

        return sol(strs, m, n, 0, 0, 0);
    }
};