
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
