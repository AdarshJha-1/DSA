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

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < k - 1; i++) {
            if(arr[i] < 0) {
                q.push(i);
            }
        }
        
        for(int i = k - 1; i < arr.size(); i++) {
            if(arr[i] < 0) {
                q.push(i);
            }
            
           if (q.empty()) {
                ans.push_back(0);
           } else {
                if(q.front() <= i - k) {
                q.pop();
            }
            
            if(q.empty()) {
                ans.push_back(0);
            } else {
               ans.push_back(arr[q.front()]);
            }
           }
        }
        return ans;
    }
};
