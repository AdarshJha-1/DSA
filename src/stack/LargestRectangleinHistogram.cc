#include "iostream"
#include "vector"
#include "stack"

using namespace std;

vector<int> nextSmLeft(vector<int> arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}
vector<int> nextSmRight(vector<int> arr) {
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) { 
    int ans = 0;
    vector<int> nsl = nextSmLeft(heights);
    vector<int> nsr = nextSmRight(heights);

    for(auto it: nsl) {
        cout << it << " ";
    } 
    cout << endl;

    for(auto it: nsr) {
        cout << it << " ";
    } 
    cout << endl;


    for(int i =0; i < heights.size(); i++) {
        int temp = heights[i] * (nsr[i] - nsl[i] - 1);
        ans = max(ans, temp);
    }
    return ans;
}


int largestRectangleAreaV2(vector<int>& heights) {
    int ans = 0;
    int temp = 0;
    stack<int> st;

    for(int i = 0; i < heights.size(); i++) {
        while(!st.empty() && heights[i] < heights[st.top()]) {
            temp = st.top();
            st.pop();
            if(st.empty()) {
                temp = heights[temp] * i;
            } else {
                temp = heights[temp] * (i - st.top() - 1);
            }

            ans = max(ans, temp);
        }
        st.push(i);
    }
    while(!st.empty()) {
        temp =  heights[st.top()];
        st.pop();
        if(st.empty()) {
            temp = temp * heights.size();
        } else {
            temp = temp * (heights.size() - st.top() - 1);
        }
        ans = max(ans, temp);
    }
    return ans;
}

int main() {
    vector<int> heights = {2,0,2};
    cout << largestRectangleAreaV2(heights);
    return 0;
}
