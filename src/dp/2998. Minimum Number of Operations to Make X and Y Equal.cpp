class Solution 
{
public:
    int minimumOperationsToMakeEqual(int x, int y) 
    {
        queue<int> q;
        q.push(x);
        int count = 0;
        vector<bool> seen(10001, false);

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int curr = q.front();
                q.pop();
                if(curr == y)
                {
                    return count;
                }
                if(curr % 11 == 0 && !seen[curr / 11])
                {
                    q.push(curr / 11);
                    seen[curr / 11] = true;
                }
                if(curr % 5 == 0 && !seen[curr / 5])
                {
                    q.push(curr / 5);
                    seen[curr / 5] = true;
                }
                if(curr - 1 >= 0 && !seen[curr - 1])
                {
                    q.push(curr - 1);
                    seen[curr - 1] = true;
                }
                if(curr + 1 <= 10000 && !seen[curr + 1])
                {
                    q.push(curr + 1);
                    seen[curr + 1] = true;
                }
            }
            count++;
        }    

        return 0;
    }
};
