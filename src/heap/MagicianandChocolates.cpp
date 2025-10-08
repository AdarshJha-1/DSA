
int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    const int MOD = 1e9 + 7;
    for(int &v : B) {
        pq.push(v);
    }
    
    long long sum = 0;
    while(A-- && !pq.empty()) {
        int t = pq.top();
        pq.pop();
        sum = sum + t % MOD;
        pq.push(floor(t/2));
    }
    
    return sum % MOD;
}
