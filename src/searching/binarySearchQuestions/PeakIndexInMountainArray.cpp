#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountain(vector<int> arr){

    int s = 0;
    int e = arr.size() - 1;

    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }else if(arr[mid] > arr[mid - 1]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}


int main()
{
    // vector<int> arr = {1,3,4,6,7,8,9,5,4,2,1};
    vector<int> arr = {0,2, 0, 1};
        // cout << "Running" << endl;
    int ans = peakIndexInMountain(arr); 
        // cout << "Stop" << endl;
    cout << "Ans: " << arr[ans] << ", " << ans  << endl;
    return 0;
}
