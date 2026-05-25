class Solution 
{
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.size();
        if(s[n - 1] != '0')
        {
            return false;
        }
        queue<int> q;
        q.push(0);
        int farthest = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(curr == n - 1)
            {
                return true;
            }

            int lower = max(curr + minJump, farthest);
            int upper = min(curr + maxJump, n - 1);

            for(int i = lower; i <= upper; i++)
            {
                if(s[i] == '0')
                {
                    q.push(i);
                }
            }
            farthest = upper + 1;
        }

        return false;
    }
};
