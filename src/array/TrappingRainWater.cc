#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxHeightLeft(vector<int> arr, int start) {
    int maxEle = INT_MIN;
    for(int i = start; i >= 0; i--) {
        if(arr[i] > maxEle){
            maxEle = arr[i];
        }
    }
    return maxEle;
}

int maxHeightRight(vector<int> arr, int start) {
    int maxEle = INT_MIN;
    for(int i = start; i < arr.size(); i++) {
        if(arr[i] > maxEle){
            maxEle = arr[i];
        }
    }
    return maxEle;
}

int totalWaterTrapped(vector<int> arr){
    vector<int> waterTrapped(arr.size());
    waterTrapped[0] = 0;
    waterTrapped[arr.size() - 1] = 0;
    for(int i = 1; i < arr.size() - 1; i++) {
        int maxLeft = maxHeightLeft(arr, i - 1);
        int maxRight = maxHeightRight(arr, i + 1);
        int minEle = min(maxLeft, maxRight);
        if (minEle > arr[i]) {
            waterTrapped[i] = minEle - arr[i];
        }
        cout << maxLeft << " " << maxRight << " " << minEle << " " << waterTrapped[i] << endl; 
    }

    int total = 0;
    for(auto it : waterTrapped){
        total += it;
    }
    return total;
}
// **************************************************************************** //



vector<int> maxLeftArr(vector<int> arr) {
    vector<int> maxLeft(arr.size());
    maxLeft[0] = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        maxLeft[i] = max(maxLeft[i - 1], arr[i]);
    }
    return maxLeft;
}

vector<int> maxRightArr(vector<int> arr) {
    vector<int> maxRight(arr.size());
    maxRight[arr.size() - 1] = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], arr[i]);
    }
    return maxRight;
}
int totalWaterTrappedV2(vector<int> arr) {
    int total = 0;
    for(int i = 0; i < arr.size() - 1; i++) {
        vector<int> maxLeft = maxLeftArr(arr);
        vector<int> maxRight = maxRightArr(arr);
        int minEle = min(maxLeft[i], maxRight[i]);
        if (minEle > arr[i]) {
            total += minEle - arr[i];
        }
        cout << maxLeft[i] << " " << maxRight[i] << " " << minEle << " " << total<< endl; 
    }
    
   return total; 
}
// ******************************************************* //

int maxEleIndex(vector<int> arr) {
    int maxI = 0;
    for(int i = 1 ;i < arr.size(); i++){
        if(arr[maxI] < arr[i]) {
            maxI = i;
        }
    }
    return maxI;
}

int totalWaterTrappedV3(vector<int> arr) {
    int maxI = maxEleIndex(arr);
    int total = 0;
    int leftMax = 0;
    int rightMax = 0;
    for(int i = 0; i < maxI; i++) {
        if(leftMax > arr[i]){
            total += leftMax - arr[i];
        }else if(leftMax  < arr[i]){
            leftMax = arr[i];
        }
    }

    for(int i = arr.size() - 1; i > maxI; i--) {
        if(rightMax > arr[i]){
            total += rightMax - arr[i];        
        }
        else if(rightMax < arr[i]){
            rightMax = arr[i];
        }
    }

    return total;
}

int main() {
    vector<int> arr = {4, 2, 0, 5, 2, 6, 2, 3};
    // vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int ans = totalWaterTrapped(arr);
    int ans = totalWaterTrappedV3(arr);
    cout << ans << endl;
    return 0;
}