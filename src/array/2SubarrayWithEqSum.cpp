#include <iostream>
#include <vector>

using namespace std;

// Brute force - for loop to check with every indexs prefix and suffix sum are equal or not :0 -> O(n^2)
bool subarrayPossible(vector<int> arr) {

    for(int outer = 0; outer < arr.size(); outer++) {
    int pSum = 0;
    int sSum = 0;
        for(int inner1 = 0; inner1 <= outer; inner1++) {
            pSum += arr[inner1];
        }
        for(int inner2 = outer + 1; inner2 < arr.size(); inner2++) {
            sSum += arr[inner2];
        }
        if(pSum == sSum) {
            return true;
        }else {
            pSum = 0;
            sSum = 0;
        }
    }
    return false;
}

// O(n)
bool subArrayPos(vector<int> arr) {
    int totalSum = 0;
    for(auto it : arr) {
        totalSum += it;
    }

    int prefix = 0;
    for(int i =0 ;i < arr.size(); i++) {
        prefix += arr[i];
        int suffix = totalSum - prefix;
        if(prefix == suffix) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {3, 4, -2, 5, 8, 20, -10, 8};
    // vector<int> arr = {4, 3, 7, 0}; 
    if(subarrayPossible(arr)) {
        cout << "YES!!" << endl;
    } else {
        cout << "NO!!" << endl;
    }
    return 0;
}