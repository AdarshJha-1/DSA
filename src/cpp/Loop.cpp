#include <iostream>

using namespace std;

int main() {

    // for(int i = 0; i < 10; i++) {
    //     cout << "yayaya" << endl;
    // }

    // for(int count = 1; count <= 5; count++) {
    //     cout << count << endl;
    // }   

    int n;
    cout << "Enter n value: ";
    cin >> n;

    for (int i = 1; i <= n; i++){
        cout  << i <<  " square = " << i*i << endl;
    }

    for(int i = 1; i <= n; i++) {
        cout << i << endl;
    }
    
    return 0;
}