#include <iostream>
#include <string>
#include <queue>
using namespace std;


// Not working
int firstUniqChar(string s) {
    queue<int> q;
    // idx.push()
    for(int i = 0; i < s.size(); i++) {
        if(q.empty()) {
            q.push(i);
        } else {
            if(s[i] == s[q.front()]) {
                cout << s[i] << " " << s[q.front()];
                q.pop();
            } else {
                q.push(i);
            }
        }
    }

    if(!q.empty()) {
        return q.front();
    }
    return -1;

}


int main() {
    string s = "aadadaad";
    cout << firstUniqChar(s);
    return 0;
}
