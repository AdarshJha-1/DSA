class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &v : arr) {
            pq.push(v);
        }
        int ans = 0;
        while(pq.size() != 1) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            pq.push(f + s);
            ans += f + s;
        }
        return ans;
    }
};
