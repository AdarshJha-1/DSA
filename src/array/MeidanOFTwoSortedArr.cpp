#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> temp(n + m);
        int i = 0, j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                temp[k] = nums1[i++];
            } else {
                temp[k] = nums2[j++];
            }
            k++;
        }

        while (k < temp.size()) {
            if (i < n) {
                temp[k++] = nums1[i++];
            }
            if (j < m) {
                temp[k++] = nums2[j++];
            }
        }

        int s = temp.size();
        int mid = 0 + (s - 1 - 0) / 2;
        if (s % 2) {
            return temp[mid];
        } else {
            double ans = (temp[mid] + temp[mid + 1]) / 2.0;
            return ans;
        }

        return -1;
    }

int main() {
    vector<int> nums1 = {1,2}, nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}
