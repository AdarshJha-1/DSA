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

bool isPossible(vector<int> weights, int days, int mid) {
    int wightCanShip = 0;
    int daysTook = 1;
    for(int i = 0; i < weights.size(); i++) {
        if(wightCanShip + weights[i] <= mid) {
            wightCanShip += weights[i];
        }else {
            daysTook++;
            if(daysTook > days) {
                return false;
            }
            wightCanShip = weights[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int> weights, int days) {
    int start = maxInArray(weights);
    int end = sumOfAllEleInArray(weights);
    int mid = -1;
    int ans = -1;

    while(start <= end) {
        mid = start + (end - start) / 2;
        if(isPossible(weights, days, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> wights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int ans = shipWithinDays(wights, days);
    cout << ans << endl;
    return 0;
}