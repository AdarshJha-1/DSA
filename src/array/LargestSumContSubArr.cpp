#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int largestSunContiSubArr(vector<int> arr) {
    int maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        int currSum = 0;
        for(int j = i; j < arr.size(); j++) {
            currSum += arr[j];
            if(maxSum < currSum){
            maxSum = currSum;
            }
        }
    }
    return maxSum;
}

int kadaneAlgo(vector<int> arr) {
    int maxSum = INT_MIN;
    int prefix = 0;
    for(int i = 0; i < arr.size(); i++) {
        prefix += arr[i];
        maxSum = max(prefix, maxSum) ;
        if(prefix < 0) {
            prefix = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr = {3, 4, -5 , 8, -12, 7, 6, -2};
    // vector<int> arr = {4, -6 , 2,8};
    int ans = largestSunContiSubArr(arr);
    cout <<  ans << endl;
int ans1 = kadaneAlgo(arr);
    cout <<  ans1 << endl;
    return 0;
}