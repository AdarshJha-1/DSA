#include <iostream>
#include <vector>

using namespace std;

long long sumBetween(vector<int>& capacity, int i, int j) {
    long long sum = 0;
    for(int k = i; k <= j; k++) {
        sum += capacity[k];
    }
    return sum;
}

long long countStableSubarrays(vector<int>& capacity) {
    long long ans  = 0;
    int l = 0;
    int r = capacity.size() - 1;

    while(l < r) {
        if(capacity[0] == 0 && capacity[capacity.size() - 1] != 0) l++;
        if(capacity[capacity.size() - 1] == 0 && capacity[0] != 0) r--;

        if((r - l + 1) >= 3 && capacity[l] == capacity[r] && capacity[l] == sumBetween(capacity, l + 1, r - 1)) {
            ans++;
        }
        l++;
        r--;
    }

    return ans;
}

int main() {
    vector<int> arr = {3,3,3,0};
    cout << countStableSubarrays(arr);
    return 0;
}

// class Solution {
// public:
//     long long sumBetween(vector<int>& capacity, int i, int j) {
//         long long sum = 0;
//         for (int k = i; k <= j; k++) {
//             sum += capacity[k];
//         }
//         return sum;
//     }
//
//     long long countStableSubarrays(vector<int>& capacity) {
//         long long ans = 0;
//         int l = 0;
//         int r = capacity.size() - 1;
//
//         while (l < r) {
//             if ((r - l + 1) >= 3 && capacity[l] == capacity[r] &&
//                 capacity[l] == sumBetween(capacity, l + 1, r - 1)) {
//                 ans++;
//             }
//             l++;
//             r--;
//         }
//
//         return ans;
//     }
// };
// class Solution {
// public:
//     long long sumBetween(vector<int>& capacity, int i, int j) {
//         long long sum = 0;
//         for (int k = i; k <= j; k++) {
//             sum += capacity[k];
//         }
//         return sum;
//     }
//
//     long long countStableSubarrays(vector<int>& capacity) {
//         long long ans = 0;
//         int l = 0;
//         int r = capacity.size() - 1;
//
//         while (l < r) {
//             if(capacity[0] == 0 && capacity)
//             if ((r - l + 1) >= 3 && capacity[l] == capacity[r] &&
//                 capacity[l] == sumBetween(capacity, l + 1, r - 1)) {
//                 ans++;
//             }
//             l++;
//             r--;
//         }
//
//         return ans;
//     }
// };
