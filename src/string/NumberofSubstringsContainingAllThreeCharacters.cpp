class Solution {
public:
    bool containABC(string s) {
        char arr[3];
        for(char &c : s) {
            arr[c - 'a']++;
        }
        return arr[0] > 0 && arr[1] > 0 && arr[2] > 0;
    }

    int numberOfSubstrings(string s) {
        queue<string> q;
        string t = "";
        for(int i = 0; i < 3; i++) {
            t += s[i];
        }
        q.push(t);
        for(int i = 3; i < s.size(); i++) {
            t += s[i];
            q.push(t);
        }
        int count = 0;
        while(!q.empty()) {
            string t = q.front();
            q.pop();
            if(containABC(t)) {
                count++;
            }
            if(t.size() - 1 >= 3) {
                t.erase(t.begin());
                q.push(t);
            }

        }
    return count;
    }
};
