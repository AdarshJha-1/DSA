#include <iostream>
#include <vector>

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!m && !n)
            return;
        if (m && !n)
            return;
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) {
                nums1[k] = nums2[j];
                j--;
            } else {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }

        if(j != -1 && i == -1) {
            while(j >= 0 && k >= 0) {
                nums1[k--] = nums2[j--]; 
            }
        }
    }
int main (int argc, char *argv[]) {
    int m =3 ,n= 3;
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,4};

    merge(nums1, m, nums2, n);

    for(auto num : nums1) {
        std::cout << num << " "; 
    }
    return 0;
}
