// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> n;

        for(int i = 0; i < arr.size(); i++) {
            if(n.empty()) {
                n.push(arr[i]);
            }else if(n.top() >= 0 && arr[i] >= 0) {
                n.push(arr[i]);
            } else if(n.top() < 0 && arr[i] < 0) {
                n.push(arr[i]);
            } else {
                n.pop();
            }
        }
        
        vector<int> ans;
        while(n.size()) {
            ans.push_back(n.top());
            n.pop();
        }
        
        int s = 0;
        int e = ans.size() - 1;
        while(s <= e) {
            swap(ans[s], ans[e]);
            s++;
            e--;
        }
        return ans;
    }
};
