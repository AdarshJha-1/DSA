#include <iostream>
#include <vector>

using namespace std;

int missingNum1(int arr[], int n)
{
    int sumN = n * (n + 1) / 2;
    int sumArr = 0;
    for (int i = 0; i < n - 1; i++){
        sumArr = sumArr + arr[i];
    }
    return sumN - sumArr;
}

int missingNum(vector<int>& nums) {
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int actualSum = 0;
    for(int i = 0; i < n; i++) {
        actualSum += nums[i];
    }
    cout << sum << endl << actualSum;
    return sum - actualSum;
}

int main()
{
    int n = 7;
    // int arr[] = {1, 2, 3, 5, 6, 7};
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    // int ans = missingNum1(arr, n);
    int ans = missingNum(arr);
    cout << ans << endl;
    return 0;
}