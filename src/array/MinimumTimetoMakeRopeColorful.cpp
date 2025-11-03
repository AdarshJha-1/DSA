class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i = 0; i < colors.size() - 1; i++) {
            if(colors[i] == colors[i + 1]) {
                ans += min(neededTime[i], neededTime[i + 1]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 1, ans = 0;
        while (j < colors.size()) {
            if (colors[i] == colors[j]) {
                if (neededTime[i] < neededTime[j]) {
                    ans += neededTime[i];
                    i = j;
                } else {
                    ans += neededTime[j];
                }
            } else {
                i = j;
            }
            j++;
        }
        return ans;
    }
};
