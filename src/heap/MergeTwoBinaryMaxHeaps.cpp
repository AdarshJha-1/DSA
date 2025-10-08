// User function Template for C++
    
    class Solution {
      public:
        vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
            priority_queue<int> p;
            for(auto &v : a) {
                p.push(v);
            }
             for(auto &v : b) {
                p.push(v);
            }
            vector<int> ans;
            while(!p.empty()) {
                ans.push_back(p.top());
                p.pop();
            } 
            
            return ans;
        }
    };
