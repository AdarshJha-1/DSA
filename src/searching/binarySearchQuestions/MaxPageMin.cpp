#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxInArray(vector<int> arr) {
    int maxEle = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > maxEle); {
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

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int pageAssign = 0;
    int students = 1;
    for(int i = 0; i < n; i++) {
        if(pageAssign + arr[i] <= mid) {
            pageAssign += arr[i];
        }else {
                students++;
            if(students > m) {
                return false;
            }
                pageAssign = arr[i];
        }
    }
    return true;
}

int maxMinPag(vector<int> arr, int n, int m) {
    int start = maxInArray(arr);
    int end =  sumOfAllEleInArray(arr);
    int mid, ans;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    int ans = maxMinPag(arr, n, m);
    cout << ans << endl;
    return 0;
}