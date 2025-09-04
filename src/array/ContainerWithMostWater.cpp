// Wrong Solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeightIdx = 0;
        int ans = -1;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > height[maxHeightIdx]) {
                maxHeightIdx = i;
            }
        }

        int s = maxHeightIdx;
        int e = height.size() - 1;
        while (s <= e) {
            ans = max(ans, (e - s) * height[e]);
            e--;
        }

        return ans;
    }
};
