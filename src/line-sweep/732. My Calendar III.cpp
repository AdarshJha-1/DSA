class MyCalendarThree 
{
public:
    map<int, int> m;
    MyCalendarThree() 
    {}
    
    int book(int startTime, int endTime) 
    {
        m[startTime] += 1;
        m[endTime] -= 1;

        int maxB = 0;
        int currB = 0;

        for(auto const &[k, v] : m)
        {
            currB += v;
            maxB = max(maxB, currB);
        }

        return maxB;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
