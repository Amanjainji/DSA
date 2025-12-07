#include <bits/stdc++.h>
using namespace std;

/*
Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1..
*/
class Solution {
public:
    // memoization
    // dp -> memo table where dp[i] stores min cost to reach i
    int solve(int ind, const vector<int>& height, vector<int>& dp) {
        // If at the first stone, cost is 0
        if (ind == 0) return 0;

        // Return memoized result if already computed
        if (dp[ind] != -1) return dp[ind];

        // Initialize jumpTwo with a large value
        int jumpTwo = INT_MAX;

        // Compute cost when jumping from previous stone (ind - 1)
        int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

        // Compute cost when jumping from two stones back (ind - 2) if possible
        if (ind > 1) {
            jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }

        // Memoize and return the minimum of the two choices
        return dp[ind] = min(jumpOne, jumpTwo);
    }

    // Helper to handle edge cases and start recursion
    int frogJump(const vector<int>& height) {
        // Handle empty input
        if (height.empty()) return 0;

        // Prepare dp with -1 indicating uncomputed states
        int n = (int)height.size();
        vector<int> dp(n, -1);

        // Start from the last index
        return solve(n - 1, height, dp);
    }


    //tabulation
    int frogJump2(const vector<int>& height) {
        // Handle empty input
        if (height.empty()) return 0;

        // Fetch size of the input
        int n = (int)height.size();

        // Create dp array where dp[i] = min energy to reach i
        vector<int> dp(n, INT_MAX);

        // Base case: cost to stand on first stone is zero
        dp[0] = 0;

        // Iterate over stones from index 1 to n-1
        for (int ind = 1; ind < n; ind++) {
            // Compute cost for a jump from ind-1
            int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);

            // Initialize jumpTwo with large value
            int jumpTwo = INT_MAX;

            // If possible, compute cost for a jump from ind-2
            if (ind > 1) {
                jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            }

            // Take the minimum of the two options
            dp[ind] = min(jumpOne, jumpTwo);
        }

        // Return min energy to reach last stone
        return dp[n - 1];
    }
};

int main() {
    // Define the heights array
    vector<int> height{30, 10, 60, 10, 60, 50};

    // Create Solution instance
    Solution sol;

    // Compute and print the minimum energy
    cout << sol.frogJump(height) << endl; // Expected: 40

    return 0;
}