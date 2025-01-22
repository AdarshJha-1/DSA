#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int counter = 0;
    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        
        if (counter > maxLength)
        {
            maxLength = counter;
        }
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 0, 1};
    int ans = findMaxConsecutiveOnes(nums);
    cout << ans << endl;
    return 0;
}