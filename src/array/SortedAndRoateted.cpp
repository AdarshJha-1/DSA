#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &nums)
{
    int counter = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] > nums[i + 1]) {
            counter++;
        }
    }
    if(counter > 1) {
        return false;
    } else if(counter == 0) {
        return true;
    }
    return true;
}

int main()
{
    // vector<int> nums = {3, 4, 5, 1, 2};
    vector<int> nums = {2, 1, 3 , 4};
    // vector<int> nums = {1,2,3};
    cout << check(nums) << endl;
    return 0;
}