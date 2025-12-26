class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        vector<int> prefix_n(n + 1, 0);
        prefix_n[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (c[i - 1] == 'N') {
                prefix_n[i] = prefix_n[i - 1] + 1;
            }
            else
            {
                prefix_n[i] = prefix_n[i - 1];
            }
        }

        vector<int> suffix_y(n + 1, 0);
        suffix_y[n]= 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == 'Y') {
                suffix_y[i] = suffix_y[i + 1] + 1;
            }
            else
            {
                suffix_y[i] = suffix_y[i + 1];
            }
        }

        int minP = INT_MAX;
        int minH = INT_MAX;

        for(int i = 0; i < n + 1; i++)
        {
            int currP = prefix_n[i] + suffix_y[i];
            if(currP < minP)
            {
                minP = currP;
                minH = i;
            }
        }
        
        return minH;
    }
};
