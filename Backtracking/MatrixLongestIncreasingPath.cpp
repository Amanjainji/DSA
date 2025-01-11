#include <bits/stdc++.h>
using namespace std;

// Directions for movement: Down, Left, Right, Up
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

// Helper function to check if the move is valid
bool isSafe(int x, int y, int m, int n, int prevValue, vector<vector<int>> &matrix) {
    return (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > prevValue);
}

// Recursive function to find the longest increasing path using memoization
int dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n) {
    if (dp[x][y] != -1) return dp[x][y]; // Return if already computed

    int maxPath = 1; // At least the current cell contributes to the path

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, m, n, matrix[x][y], matrix)) {
            maxPath = max(maxPath, 1 + dfs(newX, newY, matrix, dp, m, n));
        }
    }

    return dp[x][y] = maxPath; // Memoize the result
}

// Main function to calculate the longest increasing path
int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty()) return 0;

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Memoization table

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j, matrix, dp, m, n));
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

    cout << "Longest Increasing Path: " << longestIncreasingPath(arr) << endl;
    return 0;
}
