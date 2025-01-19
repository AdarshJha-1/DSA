#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0;
    int end = numbers.size() - 1;
    vector<int> ans(2, -1);
    while(start <= end) {
        if(numbers[start] + numbers[end] == target) {
            ans[0] = start;
            ans[1] = end;
            return ans;
        } else if (numbers[start] + numbers[end] > target) {
            end--;
        } else {
            start++;
        }
    }
    return ans;
}

int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 22;
    vector<int> ans = twoSum(numbers, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}