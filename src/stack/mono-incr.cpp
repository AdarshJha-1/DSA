#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 2, 5, 1, 3};
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        cout << arr[st.top()] << endl;
        st.pop();
    }
    return 0;
}