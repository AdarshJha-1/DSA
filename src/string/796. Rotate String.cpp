class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }
        int i = 0;
        int j = 0;
        int n = s.size();
        while (goal[j] != s[i])
        {
            j++;
        }

        while (i < n)
        {
            if (s[i] != goal[j % n])
            {
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
};

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }
        int n = s.size();
        vector<int> ids;
        for (int i = 0; i < n; i++)
        {
            if (goal[i] == s[0])
            {
                ids.push_back(i);
            }
        }

        int i = 0;
        for (const auto &id : ids)
        {
            int j = id;
            while (i < n)
            {
                if (s[i] != goal[j % n])
                {
                    i = 0;
                    break;
                }
                i++;
                j++;
            }
        }
        return i == n;
    }
};

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }
        int n = s.size();
        vector<int> ids;
        for (int i = 0; i < n; i++)
        {
            if (goal[i] == s[0])
            {
                ids.push_back(i);
            }
        }

        for (const auto &id : ids)
        {
            int i = 0;
            int j = id;
            while (i < n)
            {
                if (s[i] != goal[j % n])
                {
                    break;
                }
                i++;
                j++;
            }
            if (i == n)
            {
                return true;
            }
        }
        return false;
    }
};