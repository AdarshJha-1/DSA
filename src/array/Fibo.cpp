#include <iostream>

using namespace std;

int fibonacci(int n) {
    int arr[1000];
    arr[0] = 0;
    arr[1] =  1;

    for(int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n-1];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int ans = fibonacci(n);
    cout << ans << endl;
    return 0;
}