#include<bits/stdc++.h>
using namespace std;

/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/

//Approach
/*
How it Works

Base case: if pattern finished → string must also finish.

If next char is *: two possibilities

Skip x* entirely (matchHelper(i, j+2)).

Use x* for one character, stay at j in pattern (matchHelper(i+1, j)).

Otherwise: move forward if current characters match.
*/


//recursive
bool isMatch(string s, string p) {
    return matchHelper(0, 0, s, p);
}

bool matchHelper(int i, int j, string &s, string &p) {
        //  If pattern is finished, string must also be finished
        if (j == p.size()) return i == s.size();

        // Check if current char matches
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // Case 1: next char in pattern is '*'
        if (j + 1 < p.size() && p[j+1] == '*') {
            // Option A: treat "x*" as empty → skip 2 in pattern
            // Option B: use one match (if possible) and keep pattern at j
            return matchHelper(i, j+2, s, p) ||
                   (first_match && matchHelper(i+1, j, s, p));
        } 
        // Case 2: normal match
        else {
            return first_match && matchHelper(i+1, j+1, s, p);
        }
}

//memoization
bool isMatch2(string s, string p) {
    int n = s.size(), m = p.size();
    // -1 = not computed, 0 = false, 1 = true
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return matchHelper2(0, 0, s, p, dp);
}

bool matchHelper2(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j];  // already computed

        // Base case: if pattern is finished, string must also finish
        if (j == p.size()) return dp[i][j] = (i == s.size());

        // Does current character match?
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j+1 < p.size() && p[j+1] == '*') {
            // Option 1: skip "x*"
            // Option 2: use one match (if possible) and keep pattern at j
            return dp[i][j] = (matchHelper2(i, j+2, s, p, dp) ||
                               (first_match && matchHelper2(i+1, j, s, p, dp)));
        } 
        else {
            return dp[i][j] = (first_match && matchHelper2(i+1, j+1, s, p, dp));
        }
}

//Tabulation
bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // Empty string vs empty pattern
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* that can match empty string
        for (int j = 2; j <= m; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    // Direct match or dot
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if (p[j-1] == '*') {
                    // Zero occurrences of prev char
                    dp[i][j] = dp[i][j-2];
                    // One or more if prev matches
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[n][m];
}

