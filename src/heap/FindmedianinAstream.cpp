
// TLE
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        vector<int> temp;
        for(auto &v : arr) {
            temp.push_back(v);
            sort(temp.begin(), temp.end());
            if(temp.size() % 2 == 1) {
                ans.push_back(double(temp[temp.size() / 2]));
            } else {
                ans.push_back(double((temp[temp.size() / 2] + temp[temp.size() / 2 - 1]) / 2.0));
            }
        }
        return ans;
    }
};
