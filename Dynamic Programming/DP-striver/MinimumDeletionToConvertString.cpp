#include <bits/stdc++.h>
using namespace std;

//LCS - LONGEST COMMON SUBSEQUENCE
class Solution {
public:
    // Function to find minimum insertions/deletions
    int minOperations(string s1, string s2) {
        // Get lengths of both strings
        int n = s1.length();
        int m = s2.length();

        // Create DP table of size (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the table using bottom-up approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, extend LCS
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Get LCS length
        int lcs = dp[n][m];

        // Return total operations = deletions + insertions
        return (n - lcs) + (m - lcs);
    }
};

int main() {
    Solution sol;
    string s1 = "heap", s2 = "pea";

    // Call function and print result
    cout << "Minimum operations: " << sol.minOperations(s1, s2) << endl;
    return 0;
}