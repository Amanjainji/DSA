#include <bits/stdc++.h>
using namespace std;

// Define a class named Solution
class Solution {
public:

    // Function to calculate Longest Common Subsequence
    int lcs(string s1, string s2) {
        
        // Get sizes of both strings
        int n = s1.size();
        int m = s2.size();

        // Create a dp table of size (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize first row as 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Initialize first column as 0
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill dp table using bottom-up approach
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {

                // If characters match, add 1 to previous diagonal
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 
                        1 + dp[ind1 - 1][ind2 - 1];

                // Else take max from top or left
                else
                    dp[ind1][ind2] = 
                        max(dp[ind1 - 1][ind2], 
                            dp[ind1][ind2 - 1]);
            }
        }

        // Return bottom-right value
        return dp[n][m];
    }

    // Function to find length of Longest Palindromic Subsequence
    int longestPalindromeSubsequence(string s) {
        
        // Reverse the string
        string t = s;
        reverse(s.begin(), s.end());

        // LCS of s and its reverse is the LPS
        return lcs(s, t);
    }

    // Function to find min insertions to make string a palindrome
    int minInsertion(string s) {
        
        // Get length of input string
        int n = s.size();

        // Get length of longest palindromic subsequence
        int k = longestPalindromeSubsequence(s);

        // Return total - palindromic length
        return n - k;
    }
};

// Main function
int main() {
    
    // Create object of Solution class
    Solution obj;

    // Input string
    string s = "abcaa";

    // Call minInsertion and print result
    cout << "The Minimum insertions required to make string palindrome: "
         << obj.minInsertion(s);

    return 0;
}


//leetcode 1312

/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
Example 1:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
*/
int longestCommonSubsequenceSO(string &a, string &b) {
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=1+next[j+1];
                }
                else{
                    ans=max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
}
    
int longestPalindromeSubseq(string s) {
    string revStr=s;
    reverse(revStr.begin(),revStr.end());
    return longestCommonSubsequenceSO(s,revStr);  
}

int minInsertions(string s) {
    return s.length()-longestPalindromeSubseq(s);
}

    
