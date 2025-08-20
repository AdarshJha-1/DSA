class Solution {
  public:
  
  int firstNeg(queue<int> q) {
      while(!q.empty()) {
          if(q.front() < 0) {
              return q.front();
          }
          q.pop();
      }
      return 0;
  }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        int i = 0;
        while(i != k - 1) {
            q.push(arr[i]);
            i++;
        }
        
        while(i < arr.size()) {
            q.push(arr[i]);
            ans.push_back(firstNeg(q));
            q.pop();
            i++;
        }
        return ans;
    }
};
