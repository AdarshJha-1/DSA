class Solution
{
public:
    int atleastK(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int ans = 0;
        int i = 0;
        int j = 0;

        int n = nums.size();
        int count = 0;
        while (j < n)
        {
            m[nums[j]]++;
            if (m[nums[j]] == 1)
            {
                count++;
            }
            while (count == k && i <= j)
            {
                ans += n - j;
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                {
                    count--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int forK = atleastK(nums, k);
        int forKPlus1 = atleastK(nums, k + 1);

        cout << forK << " " << forKPlus1;
        return forK - forKPlus1;
    }
};