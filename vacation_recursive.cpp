#include<bits/stdc++.h>
using namespace std;

// N: total number of days
// points: a 2D vector storing happiness points for each activity on each day
// day: the current day we are making a choice for (0-indexed)
// last_activity: the activity chosen on the previous day (0:A, 1:B, 2:C)
int solve(int N, const vector<vector<int>>& points, int day, int last_activity) {
    // Base Case: If we are past the last day, we can't gain any more happiness.
    if (day == N) {
        return 0;
    }

    int max_points = 0;

    // Try each of the 3 activities for the current day.
    for (int current_activity = 0; current_activity < 3; ++current_activity) {
        // We can only choose this activity if it's different from the last one.
        if (current_activity != last_activity) {
            // Calculate the total points for this choice:
            // Points from today's activity + max points we can get from the remaining days.
            int current_total = points[day][current_activity] + solve(N, points, day + 1, current_activity);
            
            // Keep track of the maximum points found among all valid choices.
            max_points = max(max_points, current_total);
        }
    }

    return max_points;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> points(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    // Start the recursion from day 0.
    // We pass -1 as the last_activity because there was no activity before day 0.
    cout << solve(N, points, 0, -1) << endl;

    return 0;
}