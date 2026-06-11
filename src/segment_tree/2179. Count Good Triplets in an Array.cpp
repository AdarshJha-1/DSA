class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        // brute force TLE
        set<vector<int>> s;

        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;

        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(nums1[i]);
            for (int j = i + 1; j < n; j++)
            {
                temp.push_back(nums1[j]);
                for (int k = j + 1; k < n; k++)
                {
                    temp.push_back(nums1[k]);
                    s.insert(temp);
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }

        for (int i = 0; i < m; i++)
        {
            temp.push_back(nums2[i]);
            for (int j = i + 1; j < n; j++)
            {
                temp.push_back(nums2[j]);
                for (int k = j + 1; k < n; k++)
                {
                    temp.push_back(nums2[k]);
                    if (s.contains(temp))
                    {
                        ans++;
                    }
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }

        return ans;
    }
};