#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if(!m && !n) return;
    if(m && !n) return;
    if(!m && n) {
        nums1[0] = nums2[0];
        return;
    }
    int i = m - 1;
    int j = n - 1;
    int k = nums1.size() - 1;

    while(j >= 0) {
        if(nums2[j] > nums1[i]) {
            nums1[k] = nums2[j];
            j--;
        } else {
            nums1[k] = nums1[i];
            i--;
        }
        k--;
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
