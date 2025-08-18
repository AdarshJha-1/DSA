class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(q.size() < k) return q;
        vector<int> temp;
        while(!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }
        
        for(int i = k - 1; i >= 0; i--) {
            q.push(temp[i]);
        }
        
        for(int i = k; i < temp.size(); i++) {
            q.push(temp[i]);
        }
        return q;
    }
};
