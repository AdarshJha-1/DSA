class Solution
{
public:
    int minimumIndex(vector<int> &capacity, int itemSize)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < capacity.size(); i++)
        {
            pq.push({capacity[i], i});
        }
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            if (curr.first >= itemSize)
            {
                return curr.second;
            }
        }

        return -1;
    }
};