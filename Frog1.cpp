// PURE RECURSIVE APPROACH
// #include<bits/stdc++.h>

// using namespace std;

// long long solve(vector<int>& h,int n)
// {
//         if(n == 0)return 0;

//         long long cost1 = solve(h,n-1) + abs(h[n] - h[n-1]);

//         if(n == 1)return cost1;

//         long long cost2 = solve(h,n-2) + abs(h[n] - h[n-2]);

//         return min(cost1, cost2);
// }

// int main()
// {
//     int N;
//     cin >> N;
//     vector<int> h(N);

//     for(int i = 0; i < N; ++i)
//     {
//         cin >> h[i];
//     }

//     cout << solve(h,N-1) << "\n";
//     return 0;
// }

// //Recursion + memoization

// #include<bits/stdc++.h>
// using namespace std;

// long long solve(vector<int>& h,int n,vector<long long>& dp)
// {
//     if(n == 0)
//     {
//         return 0;
//     }

//     if(dp[n] != -1)
//     {
//         return dp[n];
//     }

//     long long cost1 = solve(h,n-1,dp) + abs(h[n]-h[n-1]);

//     if(n == 1)
//     {
//         return dp[n] = cost1;
//     }

//     long long cost2 = solve(h,n-2,dp) + abs(h[n]-h[n-2]);
//     return dp[n] = min(cost1,cost2);
// }

// int main()
// {
//     int N;
//     cin >> N;
//     vector<int> h(N);

//     for(int i = 0; i < N; ++i)
//     {
//         cin >> h[i];
//     }

//     vector<long long> dp(N,-1);

//     cout << solve(h, N-1,dp) << "\n";

//     return 0;
// }

/*Iterative approach */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> h(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    if(N == 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<long long> dp(N);

    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);

    for(int i = 2; i < N; ++i)
    {
        long long cost1 = dp[i-1]+abs(h[i]-h[i-1]);
        long long cost2 = dp[i-2] + abs(h[i]-h[i-2]);

        dp[i] = min(cost1,cost2);
    }

    cout << dp[N-1] << "\n";    

    return 0;
}
