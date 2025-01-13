#include <iostream>
#include <vector>

using namespace std;


int kthMissingPosNum(vector<int> arr, int k) {
    int num = 1;
    int i =0;
    while(k!=0) {
        if(i < arr.size() && arr[i] == num) {
            i++;
        }else{
            k--;
        }
            num++;
    }
    return num - 1;
}

int kthMissBS(vector<int> arr, int k) {
    int s = 0;
    int e = arr.size() - 1;
    int m = -1;
    while(s <= e) {
        m = s + (e - s) / 2;
        int freqOfMissingNum = arr[m] - m - 1;
        if(freqOfMissingNum < k) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return s + k;
}

int main() {
    vector<int> arr = {2,3,4,7,11};
    // vector<int> arr = {1,2,3,4};
    int k = 2;
    int ans = kthMissingPosNum(arr, k);
    cout << ans << endl;
    int ansBS = kthMissBS(arr, k);
    cout << ansBS << endl;


    return 0;
}