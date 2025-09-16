class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        set<vector<int>> s;

        for (int i = 0; i < arr.size() - 2; i++) {
            for (int j = i + 1; j < arr.size() - 1; j++) {
                vector<int> temp;
                for (int k = j + 1; k < arr.size(); k++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                    temp = {};
                }
            }
        }

        for (const auto& vec : s) {
            if(vec.size() != 0) {
                ans.push_back(vec);
            }
        }
        return ans;
    }
};
