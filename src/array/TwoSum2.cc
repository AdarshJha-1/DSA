#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
  int l = 0;
  int r = numbers.size() - 1;
  while (l <= r) {
    if (numbers[l] + numbers[r] == target) {
      return {l + 1, r + 1};
    } else if (numbers[l] + numbers[r] > target) {
      r--;
    } else {
      l++;
    }
  }
  return {-1, -1};
}

int main() {
  vector<int> numbers = {2, 3, 4};
  int target = 6;

  vector<int> ans = twoSum(numbers, target);
  cout << ans[0] << " " << ans[1];
}
