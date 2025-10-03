#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cm1 = 0, c0 = 0, c1 = 0;
        for(int i = 0; i < n; i++) {
            int ele;
            cin >> ele;
            switch (ele) {
                case -1:
                    cm1++;
                    break;
                case 0:
                    c0++;
                    break;
                case 1:
                    c1++;
                    break;
            }
        }

        if(cm1 % 2 == 1) {
            c0 += 2;
            cout << c0 << endl;
        } else {
            cout << c0 << endl;
        }
    }
    return 0;
}
