#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //Memoization
    int func(int i, int j, vector<vector<int>>& dp){
        if (i == 0 && j == 0)  return 1;
        if (i < 0 || j < 0)  return 0;
        
        if (dp[i][j] != -1)  return dp[i][j];

        int up = func(i - 1, j, dp);
        int left = func(i, j - 1, dp);

        return dp[i][j] = up + left;
    }
public:
    /*Function to count the total ways to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m-1,n-1, dp);
    }

    //tabulation
    int uniquePaths2(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
            // Base condition
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }
            int up = 0;
            int left = 0;


            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
            }
        }
        // The result is stored in bottom-right cell (m-1, n-1).
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 3;
    int n = 2;
    
    //Create an instance of Solution class
    Solution sol;
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    return 0;
}