#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Memoization
    int helper(const vector<int>& arr, int k, int start, vector<int>& dp) {
        int n = (int)arr.size();

        // Base case: if start reached end, no elements left to partition
        if (start == n) return 0;

        // Return cached result if already computed for this start index
        if (dp[start] != -1) return dp[start];

        int maxSum = 0;    
        int maxElem = 0;   

        // Try partitions of length 1 to k starting at 'start'
        for (int length = 1; length <= k && start + length <= n; length++) {
            // Update max element for this partition length
            maxElem = max(maxElem, arr[start + length - 1]);

            // Calculate current sum: maxElem * length + recursive result for remaining array
            int currentSum = maxElem * length + helper(arr, k, start + length, dp);

            // Update maxSum if current partition leads to higher sum
            maxSum = max(maxSum, currentSum);
        }

        return dp[start] = maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = (int)arr.size();

        // Initialize dp array with -1 to indicate unvisited states
        vector<int> dp(n, -1);

        // Start recursion from index 0
        return helper(arr, k, 0, dp);
    }

    //Tabulation
    int maxSumAfterPartitioning2(vector<int>& arr, int k) {
        int n = (int)arr.size();

        // DP array to store max sum from index i to end
        vector<int> dp(n + 1, 0); 

        // Iterate from right to left over the array
        for (int i = n - 1; i >= 0; i--) {
            int maxElem = 0;
            int maxSum = 0;

            // Check all partitions of length 1 to k starting at i
            for (int length = 1; length <= k && i + length <= n; length++) {
                // Update maximum element for current partition
                maxElem = max(maxElem, arr[i + length - 1]);

                // Calculate sum if partition ends here
                int currentSum = maxElem * length + dp[i + length];

                // Update maxSum if currentSum is greater
                maxSum = max(maxSum, currentSum);
            }

            // Store maximum sum for subarray starting at i
            dp[i] = maxSum;
        }

        // Return max sum achievable starting at index 0
        return dp[0];
    }
};

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    Solution sol;
    cout << "Maximum sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << "\n";

    return 0;
}