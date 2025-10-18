class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        typedef pair<int, int> Ele;
        vector<Ele> temp;
        for (int i = 0; i < score.size(); i++) {
            temp.push_back({score[i], i});
        }
        priority_queue<Ele> pq(temp.begin(), temp.end());

        int pos = 1;
        while (!pq.empty()) {
            Ele s = pq.top();
            pq.pop();
            if (pos == 1) {
                ans[s.second] = "Gold Medal";
            } else if (pos == 2) {
                ans[s.second] = "Silver Medal";
            } else if (pos == 3) {
                ans[s.second] = "Bronze Medal";
            } else {
                ans[s.second] = to_string(pos);
            }
            pos++;
        }
        return ans;
    }
};
