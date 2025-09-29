#include<bits/stdc++.h>

using namespace std;

long long solve(vector<int>& h,int n)
{
        if(n == 0)return 0;

        long long cost1 = solve(h,n-1) + abs(h[n] - h[n-1]);

        if(n == 1)return cost1;

        long long cost2 = solve(h,n-2) + abs(h[n] - h[n-2]);

        return min(cost1, cost2);
}

int main()
{
    int N;
    cin >> N;
    vector<int> h(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    cout << solve(h,N-1) << "\n";
    return 0;
}

