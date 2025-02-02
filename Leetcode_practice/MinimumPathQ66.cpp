#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int& ans, int temp) {
    int m = grid.size();
    int n = grid[0].size();

    // Add the current cell value
    temp += grid[i][j];

    // If we reach the bottom-right corner, update the answer
    if (i == m - 1 && j == n - 1) {
        ans = min(ans, temp);
        return;
    }

    vis[i][j] = 1;

    // Move right
    if (j + 1 < n && vis[i][j + 1] == 0) {
        solve(grid, vis, i, j + 1, ans, temp);
    }

    // Move down
    if (i + 1 < m && vis[i + 1][j] == 0) {
        solve(grid, vis, i + 1, j, ans, temp);
    }

    // Backtrack
    vis[i][j] = 0;
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int ans = INT_MAX;
    
    // Start recursion with initial sum as grid[0][0]
    solve(grid, vis, 0, 0, ans,0);

    return ans;
}

//Memoization
int solve2(vector<vector<int>>& grid, vector<vector<int>>& memo, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();

    // If we reach the bottom-right corner, return its value
    if (i == m - 1 && j == n - 1) {
        return grid[i][j];
    }

    // If this cell is already computed, return the stored result
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int right = INT_MAX, down = INT_MAX;

    // Move right
    if (j + 1 < n) {
        right = solve2(grid, memo, i, j + 1);
    }

    // Move down
    if (i + 1 < m) {
        down = solve2(grid, memo, i + 1, j);
    }

    // Store the result in memo and return the minimum path sum from this cell
    memo[i][j] = grid[i][j] + min(right, down);
    return memo[i][j];
}

int minPathSumMem(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Initialize a memoization table with -1 (indicating uncomputed cells)
    vector<vector<int>> memo(m, vector<int>(n, -1));

    // Start from the top-left corner (0, 0)
    return solve2(grid, memo, 0, 0);
}

//Tabulation
int minPathSum2(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    // Fill first row
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    // Fill first column
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    // Fill the rest of the grid
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
}

int main(){
    //grid = [[1,3,1],[1,5,1],[4,2,1]]
    vector<vector<int>> grid= {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSumMem(grid);
}