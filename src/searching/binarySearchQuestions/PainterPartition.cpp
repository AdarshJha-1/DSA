#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int maxInArray(vector<int> arr) {
    int maxEle = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > maxEle){
            maxEle = arr[i];
        }
    }
    return maxEle;
}

int sumOfAllEleInArray(vector<int> arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

bool isPossible(vector<int> arr, int k, int mid) {
    int wallGiven = 0;
    int painters = 1;
    for(int i = 0; i < arr.size(); i++) {
        if(wallGiven + arr[i] <= mid) {
            wallGiven += arr[i];
        }else {
            painters++;
            if(painters > k) {
                return false;
            }
            wallGiven = arr[i];
        }
    }
    return true;
}

int minTime(vector<int> arr, int k) {
    int start = maxInArray(arr);
    int end = sumOfAllEleInArray(arr);
    int mid = -1;
    int ans = -1;

    while(start <= end) {
        mid = start + (end - start) / 2;
        if(isPossible(arr, k, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;
    int ans = minTime(arr, k);
    cout << ans << endl;
    return 0;
}