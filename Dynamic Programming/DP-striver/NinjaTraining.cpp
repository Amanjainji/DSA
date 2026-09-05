#include <bits/stdc++.h>
using namespace std;

/*
Approach:

We use a recursive dynamic programming (DP) approach with memoization.
The function f(day, last) calculates the maximum points from day 0 to day, given that the last activity performed was last.
last ranges from 0 to 2 for activities and is set to 3 initially, meaning no activity was done the day before the first call.
At each step, we try all activities not equal to last and recursively calculate the total points.
We store intermediate results in a 2D vector dp to avoid recalculating them.
*/

//recursive
int recursive(int day, int last, vector<vector<int>> &points) {
    if (day == 0) {
        int maxi = 0;
        // Calculate the maximum points for the first day by choosing an activity
        // different from the last one
        for (int i = 0; i <= 2; i++) {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int activity = points[day][i] + recursive(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
}
int ninjaTrainingrec(vector<vector<int>> &points) {
    int n = points.size();
    return recursive(n - 1, 3, points);      //3 means no activity performed yet
}

//Memoization
int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (dp[day][last] != -1) return dp[day][last];

    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        // Store the result in dp array and return it
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int activity = points[day][i] + func(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return func(n - 1, 3, points, dp);      //3 means no activity performed yet
}

//Tabulation
int ninjaTrainingTab(int n, vector<vector<int>>& points) {
  vector<vector<int>> dp(n, vector<int>(4, 0));

  // Initialize the DP table for the first day (day 0)
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));  // Max points for day 0 considering any activity

  for (int day = 1; day < n; day++) {
    // For each day, check all possible "last-activities" (0, 1, 2, or no previous activity 3)
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0; // Initialize dp[day][last] to 0
      // Iterate through the tasks (activities) for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          // Update the maximum points for the current day and last activity
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];
}


int main() {
    vector<vector<int>> points = {{10, 40, 70},
                                   {20, 50, 80},
                                   {30, 60, 90}};

    int n = points.size();  // Get the number of days
    cout<<ninjaTrainingrec(points)<<endl;
    cout << ninjaTraining(n, points);
}