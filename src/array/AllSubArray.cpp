#include <iostream>
#include <vector>

using namespace std;

void printAllSubArray(vector<int> arr) {
    int n = arr.size();
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int k = start; k <= end; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> arr = {4, 3, 7, 2};
    printAllSubArray(arr);
    return 0;
}