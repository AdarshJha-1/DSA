using ll = long long;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;

        set<pair<int, int>> st;
        priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        st.insert({0, 0});

        for (int l = 0; !pq.empty() && l < k; l++)
        {
            auto [s, ij] = pq.top();
            pq.pop();
            auto [i, j] = ij;
            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < nums1.size() && !st.count({i + 1, j}))
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            if (j + 1 < nums2.size() && !st.count({i, j + 1}))
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
        }

        return ans;
    }
};