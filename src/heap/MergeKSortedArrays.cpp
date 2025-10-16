class Solution {
  public:
 
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> ans;
        typedef pair<int, pair<int, int>> Ele;
        priority_queue<Ele, vector<Ele>, greater<Ele>> pq;
        for(int i = 0; i < K; i++) {
            pq.push({arr[i][0], {i, 1}});
        }
        
        while(!pq.empty()) {
            Ele e = pq.top();
            ans.push_back(e.first);
            int i = e.second.first, j = e.second.second;
            if(i + 1 < K + 1 && j < K) {
                pq.push({arr[i][j], {i, j + 1}});
            }
            pq.pop();
        }
        
        return ans;
    }
};
