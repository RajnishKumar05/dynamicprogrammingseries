// #include<bits/stdc++.h>
// using namespace std;

// int solve(int N, const vector<vector<int>>& points,int day,int last_activity,vector<vector<int>>& dp)
// {
//     if(day == N) return 0;

//     if(dp[day][last_activity+1] != -1)
//     {
//         return dp[day][last_activity+1];
//     }
//     int max_points = 0;

//     for(int current_activity = 0; current_activity < 3; ++current_activity)
//     {
//         if(current_activity != last_activity)
//         {
//             int current_total = points[day][current_activity] + solve(N, points,day+1,current_activity,dp);
//             max_points  = max(max_points, current_total);

//         }
//     }
//     return dp[day][last_activity+1] = max_points;
// }

// int main()
// {
//     int N;
//     cin >> N;

//     vector<vector<int>> points(N,vector<int>(3));
//     for(int i = 0; i < N; ++i)
//     {
//         cin >> points[i][0] >> points[i][1] >> points[i][2];
//     }
//     vector<vector<int>> dp(N,vector<int>(4,-1));

//     cout << solve(N, points,0,-1,dp) << endl;

//     return 0;
// }

//iterative approach


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> p(N,vector<int>(3));

    for(int i = 0; i < N; ++i)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];

    }
    

    vector<vector<int>> dp(N,vector<int>(3,0));

    dp[0][0] = p[0][0];
    dp[0][1] = p[0][1];
    dp[0][2] = p[0][2];

    for(int i = 1; i < N; ++i)
    {
        dp[i][0] = p[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = p[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = p[i][2] + max(dp[i-1][0],dp[i-1][1]);
        
    }

    cout << max({dp[N-1][0],dp[N-1][1],dp[N-1][2]}) << endl;

    return 0;
}