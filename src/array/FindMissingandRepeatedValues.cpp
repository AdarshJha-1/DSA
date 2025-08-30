// #include <iostream>
// #include <unordered_map>
// #include <vector>
//
// int main () {
//     int n = 3;
//     std::unordered_map<int, int> m(n * n);
//     for(int i = 1; i <= n * n; i++) {
//         m[i] = 0;
//     }
//     for(auto it : m) {
//         std::cout << it.first << " : " << it.second << std::endl;
//     }
//
//     std::vector<std::vector<int>> v = {{1,2}, {3,4}};
//     for(auto r : v) {
//         for(auto c : r) {
//             std::cout << c << " "; 
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }
//
// ROUGH WORK
//


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeat = INT_MIN;
        int missing = INT_MIN;
        unordered_map<int, int> m(n*n);

        for(int i = 1; i <= n * n; i++) {
            m[i] = 0;
        }
        for(auto r : grid) {
            for(auto c : r) {
                m[c]++;
            }
        }

        for(auto it : m) {
            if(it.second == 2) {
                repeat = it.first;
            }

            if(it.second == 0) {
                missing = it.first;
            }
        }

        return {repeat, missing};
    }
};
