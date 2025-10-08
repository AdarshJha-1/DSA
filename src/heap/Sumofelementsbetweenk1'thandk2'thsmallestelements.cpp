class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        priority_queue<int> p1;
        priority_queue<int> p2;
        
        for(long long i = 0; i < K1; i++) {
            p1.push(A[i]);
        }
        for(long long i = 0; i < K2 - 1; i++) {
            p2.push(A[i]);
        }
        
        for(long long i = K1; i < N; i++) {
            if(A[i] < p1.top()) {
                p1.pop();
                p1.push(A[i]);
            }
        }
        
        for(long long i = K2 - 1; i < N; i++) {
            if(A[i] < p2.top()) {
                p2.pop();
                p2.push(A[i]);
            }
        }
        
        int sum = 0;
        while(!p2.empty()) {
            sum += p2.top();
            p2.pop();
        }
        
        while(!p1.empty()) {
            sum -= p1.top();
            p1.pop();
        }
        
        return sum;
    }
};


class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long i = 0; i < N; i++) {
            pq.push(A[i]);
        }
        K2 -= K1;
        while(K1--) {
            pq.pop();
            // K1--;
        }
        long long i = 1;
        while(i < K2) {
            sum += pq.top();
            pq.pop();
            i++;
        }
        
        return sum;
    }
};
