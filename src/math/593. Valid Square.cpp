class Solution
{
public:
    int distance(vector<int> &p1, vector<int> &p2)
    {
        return pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2);
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        set<int> s;
        s.insert(distance(p1, p2));
        s.insert(distance(p2, p3));
        s.insert(distance(p3, p4));
        s.insert(distance(p4, p1));
        s.insert(distance(p1, p3));
        s.insert(distance(p2, p4));

        if (s.size() == 2 && s.find(0) == s.end())
        {
            return true;
        }
        return false;
    }
};