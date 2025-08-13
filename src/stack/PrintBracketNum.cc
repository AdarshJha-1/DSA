#include "iostream"
#include "stack"
#include "vector"

using namespace std;

vector<int> bracketNumbers(string str) {
    stack<char> st;
    vector<int> ans;
    int counter = 0;
    for(int i = 0; i < str.size(); i++) {
        if(st.empty()) {
            st.push(str[i]);
            counter += 1;
            ans.push_back(counter);
        } else if(str[i] == ')' && st.top() == '(') {
            ans.push_back(counter);
            st.pop();
        } else {
            st.push(str[i]);
            counter += 1;
            ans.push_back(counter);
        }
    }
    return ans;
}

int main() {
    string str = "(aa(bdc))p(dee)";
    vector<int> ans = bracketNumbers(str);

    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}
