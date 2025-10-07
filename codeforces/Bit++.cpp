#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0;
    while(n--) {
        string str;
        cin >> str;
        if(str == "++X") {
            ++x;
        } else if(str == "X++"){
            x++;
        } else if(str == "--X"){
            --x;
        } else if(str == "X---") {
            x--;
        } else {
            break;
        }
    }

    cout << x << endl;
    return 0;
}
