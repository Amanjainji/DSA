#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Memoization
    int f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case
        if (idx == 0) {
            if (target == 0 && arr[0] == 0) return 2;        // choose or not choose
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int notTake = f(idx - 1, target, arr, dp);
        int take = 0;
        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = take + notTake;
    }

    int countPartitions(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalSum + d) % 2 != 0 || d > totalSum) return 0;

        int K = (totalSum + d) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        return f(n - 1, K, arr, dp);
    }

    // Tabulation
    int countPartitions2(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalSum + d) % 2 != 0 || d > totalSum) return 0;

        int K = (totalSum + d) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // Base case initialization
        if (arr[0] == 0) {
            dp[0][0] = 2;         // pick or not pick
        } else {
            dp[0][0] = 1;         // not pick
        }
        if (arr[0] != 0 && arr[0] <= K)
            dp[0][arr[0]] = 1;    // pick //< because bottom up 

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= K; t++) {
                int notTake = dp[i - 1][t];
                int take = 0;
                if (arr[i] <= t)
                    take = dp[i - 1][t - arr[i]];

                dp[i][t] = take + notTake;
            }
        }

        return dp[n - 1][K];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    int d = 4;
    cout << sol.countPartitions(arr, d) << endl;    //2    4+3-2-1  4+2+1-3
    return 0;
}