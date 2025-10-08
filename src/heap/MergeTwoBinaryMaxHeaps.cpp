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

// User function Template for C++

class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(a[i]);
        }
        
        for(int i = 0; i < m; i++) {
            ans.push_back(b[i]);
        }
        
        int s = ans.size();
        for(int i = (s / 2) - 1; i >=0; i--) {
            int t = i;
            while(t * 2 + 1 < s) {
                int lg = t, l = t * 2 + 1, r = t * 2 + 2;
                if(l < s && ans[l] > ans[lg]) lg = l;
                if(r < s && ans[r] > ans[lg]) lg = r;
                if(lg == t) break;
                swap(ans[lg], ans[t]);
                t = lg;
            }
        }
        
        return ans;
    }
};
