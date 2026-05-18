class Solution 
{
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        for(int i = n - 1; i >= 0; i--)
        {
            m[arr[i]].push_back(i);
        }

        vector<bool> seen(n, false);

        queue<int> q;
        q.push(0);
        seen[0] = true;
        int counter = 0;
        
        while(!q.empty())
        {
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                int temp = q.front();
                q.pop();
                if(temp == n - 1)
                {
                    return counter;
                }
                if(temp - 1 >= 0 && !seen[temp - 1])
                {
                    q.push(temp - 1);
                    seen[temp - 1] = true;
                }
                if(temp + 1 < n && !seen[temp + 1])
                {
                    q.push(temp + 1);
                    seen[temp + 1] = true;
                }

                for(const auto& idx : m[arr[temp]])
                {
                    if(!seen[idx] && idx != temp)
                    {
                        q.push(idx);
                        seen[idx] = true;
                    }
                }
                m[arr[temp]].clear(); // this i found online i am sry
            }
            counter++;
        }
        return -1;
    }
};
