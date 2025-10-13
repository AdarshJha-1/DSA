
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        vector<int> temp;
        for(auto &r : mat) {
            for(auto &c : r) {
                temp.push_back(c);
            }
        }
        
        sort(temp.begin(), temp.end());
        return temp[k - 1];
    }
};




class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &r : mat) {
            for(auto &c : r) {
                pq.push(c);
            }
        }
        
        while(k != 1 && k--) {
            pq.pop();
        }
        
        return pq.top();
    }
};

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        
        using Node = pair<int, pair<int, int>>;
        priority_queue<Node, vector<Node>, greater<Node>>pq;
        for(int i = 0; i < mat.size(); i++) {
            pq.push({mat[i][0], {i, 1}});
        }
        
        while(k != 1 && k--) {
            Node t = pq.top();
            pq.pop();
            if(t.second.second < mat[0].size()) {
                pq.push({
                    mat[t.second.first][t.second.second],
                   { t.second.first,
                    t.second.second + 1}
                });
            }
        }
        
        return pq.top().first;
    }
};
