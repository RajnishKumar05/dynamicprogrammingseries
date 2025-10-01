// Recursive approach

#include<bits/stdc++.h>
using namespace std;

long long solve(const vector<int>& h, int N, int K, int i)
{
    if(i == 0) return 0;

    long long min_cost = LLONG_MAX;

    for(int j = 1; j <= K; ++j) 
    {
        if(i - j >= 0)
        {
            long long curr_cost = solve(h,N,K,i-j) + abs(h[i] - h[i-j]);
            min_cost = min(min_cost,curr_cost);
        }
    }
    return min_cost;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> h(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    cout << solve(h,N,K,N-1) << "\n";
    return 0;
}
//memoization approach

#include<bits/stdc++.h>
using namespace std;

long long solveMemo(const vector<int>& h, int N, int K, int i, vector<long long>& dp)
{
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];

    long long min_cost = LLONG_MAX;

    for(int j = 1; j <= K; ++j)
    {
        if(i - j >= 0)
        {
            long long curr_cost = solveMemo(h,N,K,i-j,dp) + abs(h[i] - h[i-j]);
            min_cost = min(min_cost,curr_cost);
        }
    }
    return dp[i] = min_cost;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    vector<long long> dp(N, -1);  

    for(int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    cout << solveMemo(h,N,K,N-1,dp) << "\n";
    return 0;
}