#include <bits/stdc++.h>
#include <cstring>
using namespace std;

const int N = 1e5+10;

// 0 1 1 2 3 5 8 13 21..... -> c = b + a;
int dp[N];

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() 
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fib(n) << endl;
}

