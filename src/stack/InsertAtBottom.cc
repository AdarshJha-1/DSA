#include "iostream"
#include "stack"

using namespace std;
stack<int> insertAtBottom(stack<int> st, int x) {
         stack<int> temp;
    while(st.size()){
        temp.push(st.top());
        st.pop();
    }

    st.push(x);
    while(temp.size()){
        st.push(temp.top());
        temp.pop();
    }

    return st;

    }

int main() {
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);
    int x = 2;


    st = insertAtBottom(st, x);
    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
