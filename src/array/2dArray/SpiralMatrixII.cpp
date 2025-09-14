#include <iostream>
#include <vector>

using namespace std;


/*
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int num = 1;
    int flag = 1;
    for(int i = 0; i < n; i++) {
        if(flag) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = num++;
            }
        } else {
            for(int j = n - 1; j >= 0; j--) {
                ans[i][j] = num++;
            }
        }
        flag = !flag;
    }
    return ans;
}       
*/

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int t = 0;
    int b = n - 1;
    int l = 0;
    int r = n -1;
    int num = 1;

    while(l <= r && t <= b) {
        for(int i = l; i <= r; i++) {
            ans[t][i] = num++;
        }
        t++;

        for(int i = t; i <= b; i++) {
            ans[i][b] = num++;
        }
        r--;

        for(int i = r; i >= l; i--) {
            ans[b][i] = num++;
        }
        b--;

        for(int i = b; i >= t; i--) {
            ans[i][l] = num++;
        }
        l++;
    }
    return ans;
}


int main() {
    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);
    for(vector<int> r : ans) {
        for(int num : r) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

