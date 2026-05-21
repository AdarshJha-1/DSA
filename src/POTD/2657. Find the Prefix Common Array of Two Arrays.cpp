class Solution 
{
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> m;

        int count = 0;
        for(int i = 0; i < n; i++)
        {
            m[A[i]]++;
            m[B[i]]++;
            if(A[i] == B[i])
            {
                if(m[A[i]] == 2)
                {
                    count++;
                }
            }
            else
            {
                if(m[A[i]] == 2)
                {
                    count++;
                }
                if(m[B[i]] == 2)
                {
                    count++;
                }    
            }
            ans[i] = count;
        }        
        return ans;
    }
};
