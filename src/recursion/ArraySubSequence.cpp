#include <iostream>
#include <vector>


void subsequence(const std::vector<int>& arr, int idx, std::vector<std::vector<int>>& ans, std::vector<int>& temp) {
    if(idx == arr.size()) {
        ans.push_back(temp);
        // temp.pop_back();
        return;
    }
    // Yes
    temp.push_back(arr[idx]);
    subsequence(arr, idx + 1, ans, temp);
    temp.pop_back();

    // No
    subsequence(arr, idx + 1, ans, temp);

}

int main() {

    std::vector<int> arr = {1, 2, 3};
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;
    subsequence(arr,0, ans, temp);
    for(const auto& r : ans) {
        std::cout << "[ ";
        for(const auto& c : r) {
            std::cout << c << " ";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    return 0;
}
