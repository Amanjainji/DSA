#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Memoization
    int count(string &s, int i, int j, vector<vector<int>> &dp) {
        // If i > j, no valid subsequence
        if (i > j) return 0;

        // If i == j, single character is a palindrome
        if (i == j) return 1;

        // If already computed, return from dp
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, count all palindromic subsequences 
        // from both ends and middle + 1
        if (s[i] == s[j])
            dp[i][j] = count(s, i + 1, j, dp) + 
                             count(s, i, j - 1, dp) + 1;
        else
            // Subtract overlapping part if chars don’t match
            dp[i][j] = count(s, i + 1, j, dp) + count(s, i, j - 1, dp) -
                              count(s, i + 1, j - 1, dp);

        return dp[i][j];
    }
public:
    // Function to count palindromic subsequences using memoization
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        // Initialize a 2D DP array with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // Call the recursive function on the full string
        return count(s, 0, n - 1, dp);
    }

    //Tabulation
    int countPalindromicSubsequences2(string s) {
        int n = s.size();
        // Create a 2D DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill the DP table for substrings of increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                // If characters match
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                else
                    // Remove overlapping part
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << sol.countPalindromicSubsequences(s) << endl;
    return 0;
}