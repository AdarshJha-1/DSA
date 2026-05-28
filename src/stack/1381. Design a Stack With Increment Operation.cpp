class CustomStack 
{
public:

    stack<int> st;
    int ms;

    CustomStack(int maxSize) 
    {
        ms = maxSize;   
    }
    
    void push(int x) 
    {
        if(st.size() + 1 <= ms)
        {
            st.push(x);
        }   
    }
    
    int pop() 
    {
        if(!st.empty())
        {
            int tp = st.top();
            st.pop();
            return tp;
        } 
        return -1;
    }
    
    void increment(int k, int val) 
    {
        stack<int> temp;
        while(!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }

        while(k-- && !temp.empty())
        {
            st.push(temp.top() + val);
            temp.pop();
        }
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
