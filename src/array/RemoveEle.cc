#include "iostream"
#include "vector"

using namespace std;

int removeElement(vector<int>& nums, int val) {
        vector<int> t;
        for (auto it : nums) {
            if (it != val) {
                t.push_back(it);
            }
        }

        for (int i = 0; i < t.size(); i++) {
            nums[i] = t[i];
        }
        return t.size() - 1;
  }

int main () {
  vector<int> nums = {3,2,2,3};
  for (auto it : nums) {
    cout << it << " ";
  }
  cout << endl;
  cout << removeElement(nums, 3);
  for (auto it : nums) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
