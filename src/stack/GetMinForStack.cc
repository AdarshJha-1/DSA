class Solution {
    
    stack<int> st;
  public:
    Solution() {   
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(st.empty()) {
            x = x * 100 + x;
            st.push(x);
        }else {
            int minInStack = min(st.top() % 100, x);
            x = (x * 100) + minInStack;
            st.push(x);
        }
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(!st.empty()) {
            st.pop();
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        if(!st.empty()) {
        return st.top() / 100;
        }
        return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()) {
            return -1;
        }
        return st.top() % 100;
    }
};


class Solution {
    
    stack<int> st;
    stack<int> min;
  public:
    Solution() {
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        st.push(x);
        if(!min.empty()) {
            if(x < min.top()) {
                min.push(x);
            } else {
                min.push(min.top());
            }
        } else {
            min.push(x);
        }
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(!st.empty() && !min.empty()) {
            st.pop();
            min.pop();
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        if(!st.empty()) {
        return st.top();
        }
        return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty() && min.empty()) {
            return -1;
        }
                return min.top();

    }
};
