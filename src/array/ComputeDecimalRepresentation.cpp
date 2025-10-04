#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> decimalRepresentation(int n) {
    if(n >= 1 && n <= 9) return {n};
    vector<int> ans;
    int mul = 1;
    while(n) {
        if(n % 10 > 0) {
        ans.push_back((n % 10) * mul);
        }
        mul *= 10; 
        n = n / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 507;
    vector<int> ans = decimalRepresentation(n);
    for(auto &n : ans) {
        cout << n << " ";
    }
    return 0;
}
