// Recursive approach

#include<bits/stdc++.h>
using namespace std;

long long solve(const vector<int>& h, int N, int K, int i)
{
    if(i == 0) return 0;

    long long min_cost = LLONG_MAX;

    for(int j = 1; j <= K; ++j)  // Changed from j < K to j <= K
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