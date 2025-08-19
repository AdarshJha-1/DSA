class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int pro_nz = 1;
        int z_c = 0;
        vector<int> ans;

        for(auto num : nums) {
            if(num == 0) {
                z_c++;
            } else {
                pro_nz *= num;
            }
            pro *= num; 
        }

        for(auto num : nums) {
            if(num == 0) {
                if(z_c > 1) {
                    ans.push_back(pro);
                } else {
                    ans.push_back(pro_nz);
                }
            } else {
                ans.push_back(pro / num);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int pro = 1;
            for(int j = 0; j < nums.size(); j++) {
                if(j != i) {
                    pro *= nums[j];
                }
            }
            ans.push_back(pro);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};

/*
  [1,2,3,4]

  l = [1, 1, 2, 6]
  r = [24, 12, 4, 1]

  a = [24, 12 8, 6]  
 
 [1, 1, 2, 6]
 p = 1;

 [1, 1, 2, 6]
  */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }
        int p = 1;

        for(int i = nums.size() - 2; i >= 0; i--) {
            p *= nums[i + 1];
            ans[i] = ans[i] * p;
        }
        return ans;
    }
};
