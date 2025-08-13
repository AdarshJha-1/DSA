class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for(int i = 0; i < 2 * arr.size(); i++) {
            while(!st.empty() && arr[i % n] > arr[st.top()] ) {
                ans[st.top()] = arr[i % n];
                st.pop();
            }
            st.push(i % n);
        }

    return ans;

    }
};
