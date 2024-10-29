#include <iostream>

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

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 5, 6, 7};
    int ans = missingNum1(arr, n);
    cout << ans << endl;
    return 0;
}