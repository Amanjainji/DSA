#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Recursion + Memoization
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if (i < 0 || j < 0 || matrix[i][j] == 1) return 0;
        else if(i == 0 && j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];

        int up = func(i - 1, j, matrix, dp);
        int left = func(i, j - 1, matrix, dp);

        return dp[i][j] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize DP table to memoize results
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        
        //Return the total number of paths
        return func(m-1, n-1, matrix, dp);
    }


    //Tabulation
    int func2(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Base conditions
                if (matrix[i][j] == 1) {
                    /* If there's an obstacle at the 
                    cell, no paths can pass through it*/
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    /* If we are at the starting 
                    point, there is one path to it*/
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
        /* The final result is stored in dp[m-1][n-1],
        which represents the destination*/
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles2(vector<vector<int>>& matrix) {
        int m = matrix.size();   
        int n = matrix[0].size(); 

        vector<vector<int>> dp(m, vector<int>(n, 0));

        return func2(m, n, matrix, dp);
    }

    // Space optimized
    int func3(int m, int n, vector<vector<int>>& matrix) {
        
        vector<int> prev(n, 0), curr(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Base conditions
                if (matrix[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }
            
            prev = curr;
        }

        /* The final result is stored in dp[m-1][n-1],
        which represents the destination*/
        return prev[n-1];
    }

    int uniquePathsWithObstacles3(vector<vector<int>>& matrix) {
        int m = matrix.size();   
        int n = matrix[0].size(); 

        // Return the total number of paths
        return func3(m, n, matrix);
    }
};

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    Solution sol;

    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;
    return 0;
}