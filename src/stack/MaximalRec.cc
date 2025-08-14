
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int temp = 0;
        stack<int> st;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                temp = st.top();
                st.pop();
                if (st.empty()) {
                    temp = heights[temp] * i;
                } else {
                    temp = heights[temp] * (i - st.top() - 1);
                }

                ans = max(ans, temp);
            }
            st.push(i);
        }
        while (!st.empty()) {
            temp = heights[st.top()];
            st.pop();
            if (st.empty()) {
                temp = temp * heights.size();
            } else {
                temp = temp * (heights.size() - st.top() - 1);
            }
            ans = max(ans, temp);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
