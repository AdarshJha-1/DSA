// Not working wrong
class Solution 
{
public:
    int maxJumps(vector<int>& arr, int d) 
    {
        int n = arr.size();
        int ans = 0;

        vector<bool> seen(n, false);
        queue<pair<int, int>> q;
        if(arr[0] > arr[1])
        {
            q.push({0, 1});
            seen[0] = true;
        }
        if(arr[n - 1] > arr[n - 2])
        {
            q.push({n - 1, 1});
            seen[n - 1] = true;
        }
        for(int i = 1; i < n - 1; i++)
        {
            if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
            {
                q.push({i, 1});
                seen[i] = true;
            }
        }      

        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto& [curr, v] = q.front();
                ans = max(ans, v);
                q.pop();
                // back
                for(int i = 1; i <= d; i++)
                {
                    int idx = curr - i;
                    if(idx >= 0 && arr[idx] < arr[curr])
                    {
                        q.push({idx, v + 1});
                    }
                }
                // front
                for(int i = 1; i <= d; i++)
                {
                    int idx = curr + i;
                    if(idx < n && arr[idx] < arr[curr])
                    {
                        q.push({idx, v + 1});
                    }
                }
            }
        }
        return ans;
    }
};


class Solution 
{
public:

    vector<int> dp;

    int dfs(vector<int>& arr, int d, int curr, int n) 
    {
        if(curr < 0 || curr >= n)
        {
            return 0;
        }
        if(dp[curr] != -1)
        {
            return dp[curr];
        }

        // left
        int left = 1;
        for(int i = 1; i <= d; i++)
        {
            int idx = curr - i;
            if(idx >= 0 && arr[idx] < arr[curr])
            {
                left = max(left, dfs(arr, d, idx, n) + 1);
            }
            else
            {
                break;
            }
        }
        
        // right
        int right = 1;
        for(int i = 1; i <= d; i++)
        {
            int idx = curr + i;
            if(idx < n && arr[idx] < arr[curr])
            {
                right = max(right, dfs(arr, d, idx, n) + 1);
            }
            else 
            {
                break;
            }
        }

        return dp[curr] = max(left, right);
    }

    int maxJumps(vector<int>& arr, int d) 
    {
        int ans = 1;
        int n = arr.size();
        dp.resize(n, -1);
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(arr, d, i, n));   
        }

        return ans;
    }
};
