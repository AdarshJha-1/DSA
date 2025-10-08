class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        int n = stones.size();
        for(int i = 0; i < n ; i++) {
            sort(stones.begin(), stones.end());
            int f = n - 2, s = n - 1;
            stones[f] = abs(stones[f] - stones[s]);
            stones[s] = 0;
        }
        return stones[n - 2];
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &s : stones) pq.push(s);
        while(pq.size() != 1) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            pq.push(abs(f - s));
        }

        return pq.top();
    }
};
