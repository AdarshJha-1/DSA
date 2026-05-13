class MyCalendarTwo 
{
public:
    map<int, int> m;
    MyCalendarTwo() 
    {
    }
    
    bool book(int startTime, int endTime) 
    {
        m[startTime] += 1;
        m[endTime]  -= 1;

        int booked = 0;
        int curr = 0;
        for(auto const& [k, v] : m)
        {
            curr += v;
            booked = max(booked, curr);
        }

        if(booked > 2)
        {
            m[startTime] -= 1;
            m[endTime] += 1;
            
            if(m[startTime] == 0)
            {
                m.erase(startTime);
            }
            if(m[endTime] == 0)
            {
                m.erase(endTime);
            }
            return false;
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
