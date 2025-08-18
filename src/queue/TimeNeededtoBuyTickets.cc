class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int count = 0;
        for(int i = 0; i < tickets.size(); i++) {
            q.push(tickets[i] * 100 + i);
        }

        while(!q.empty()) {
            if(q.front() - 100 < 100) {
                if(q.front() % 100 == k) {
                    return count + 1;
                }
            } else {
                q.push(q.front() - 100);
            }
            count++;
            q.pop();
        }
        return -1;
    }
};
