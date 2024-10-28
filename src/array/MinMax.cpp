#include <iostream>
#include<climits>
using namespace std;

int main() {
    int arr[5] = {23, 34, 32,13, 33};
    int max = INT_MIN;
    int min = INT_MAX;

    for(int i = 0; i < 5; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    for(int i = 0; i < 5; i++) {
        if(arr[i] < min) {
            min =  arr[i];
        }
    }

cout << "Min value: " << min << endl;
cout << "Max value: " << max << endl;
    return 0;
}