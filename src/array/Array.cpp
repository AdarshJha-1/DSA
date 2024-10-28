#include <iostream>

using namespace std;

int main() {
    // int arr[5] = {1, 2, 3, 4, 5};
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr[5] = {1, 2};
    // int arr[5] = {0};
    int arr[5];
    cout << "Enter array values\n";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }   
    cout << endl;
    cout << sizeof(arr)/sizeof(arr[0]) << endl;
    
    return 0;
}