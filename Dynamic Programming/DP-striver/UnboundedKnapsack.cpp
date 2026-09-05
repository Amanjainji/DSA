#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //recursion + memoization
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
        // Base case
        if (ind == 0) {
            // Calculate and return the maximum value for the given weight limit
            return (W / wt[0]) * val[0];
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);

        int taken = INT_MIN;

        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

        return dp[ind][W] = max(notTaken, taken);
    }

    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapsackUtil(wt, val, n - 1, W, dp);
    }

    //Tabulation
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int i = wt[0]; i <= W; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        // Loop through all items starting from second
        for (int ind = 1; ind < n; ind++) {
            // Loop through all capacities from 0 to W
            for (int cap = 0; cap <= W; cap++) {
                // Case 1: Not taking the current item
                int notTaken = dp[ind - 1][cap];

                // Case 2: Taking the current item (if it fits)
                int taken = INT_MIN;
                if (wt[ind] <= cap)
                    taken = val[ind] + dp[ind][cap - wt[ind]];

                // Store the best of both choices
                dp[ind][cap] = max(notTaken, taken);
            }
        }

        // Return the maximum value possible for n items and capacity W
        return dp[n - 1][W];
    }
};



int main() {
    // Initialize item weights
    vector<int> wt = {2, 4, 6};

    // Initialize item values
    vector<int> val = {5, 11, 13};

    // Weight capacity of the knapsack
    int W = 10;

    // Number of items
    int n = wt.size();

    // Create Solution object
    Solution obj;

    // Output the result
    cout << "The Maximum value of items the thief can steal is " 
         << obj.unboundedKnapsack(n, W, val, wt) << endl;

    return 0;
}