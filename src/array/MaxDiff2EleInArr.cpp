#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxDiff(vector<int> arr) {
    int max = INT_MIN;
    int largestEle = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(largestEle < arr[i]){
            swap(largestEle, arr[i]);
        }
    }

    for(int i = 0; i < arr.si)
    return max;
}

int main() {
    vector<int> arr = {9,5,8,12,2,3,7,4};

    return 0;
}
