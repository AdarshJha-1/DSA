class Solution
{
public:
    int beautySum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                vector<int> arr(26, 0);
                for (int k = i; k <= j; k++)
                {
                    arr[s[k] - 'a']++;
                }
                int minF = INT_MAX, maxF = 0;
                char minE, maxE;
                for (int i = 0; i < 26; i++)
                {
                    if (arr[i] > 0)
                    {
                        if (arr[i] > maxF)
                        {
                            maxF = arr[i];
                            maxE = i + 'a';
                        }
                        if (arr[i] < minF)
                        {
                            minF = arr[i];
                            minE = i + 'a';
                        }
                    }
                }
                ans += (maxF - minF);
            }
        }

        return ans;
    }
};
class Solution
{
public:
    int beautySum(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++)
            {
                int maxF = 0;
                int minF = INT_MAX;
                freq[s[j] - 'a']++;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        maxF = max(maxF, freq[k]);
                        minF = min(minF, freq[k]);
                    }
                }
                ans += (maxF - minF);
            }
        }
        return ans;
    }
};