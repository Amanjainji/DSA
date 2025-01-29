#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s){
    int n = s.length();
    if (n == 0) return "";
    
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1, start = 0;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) 
        dp[i][i] = true;

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check substrings of length 3 or more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }

return s.substr(start, maxLength);

}

int main(){
    string s="babad";
    cout<<longestPalindrome(s);
}