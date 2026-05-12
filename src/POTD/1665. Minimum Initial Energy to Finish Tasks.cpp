class Solution {
public:
  int minimumEffort(vector<vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(), [](const auto &a, const auto &b) {
      return (a[1] - a[0] > b[1] - b[0]);
    });

    int totalReq = 0;
    for (const auto &t : tasks) {
      totalReq += t[0];
    }

    int currAvail = totalReq;
    for (const auto &t : tasks) {
      if (currAvail < t[1]) {
        int more = t[1] - currAvail;
        totalReq += more;
        currAvail += more;
      }
      currAvail -= t[0];
    }

    return totalReq;
  }
};
