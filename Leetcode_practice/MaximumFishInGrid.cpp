#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& grid, vector<vector<bool>>& vis, int& temp, int row, int col, int m, int n) {
    // Add current cell value to temp
    temp += grid[row][col];
    vis[row][col] = true;

    // Explore all 4 directions
    // Right
    if (col < n - 1 && grid[row][col + 1] > 0 && !vis[row][col + 1]) {
        solve(grid, vis, temp, row, col + 1, m, n);
    }
    // Left
    if (col > 0 && grid[row][col - 1] > 0 && !vis[row][col - 1]) {
        solve(grid, vis, temp, row, col - 1, m, n);
    }
    // Up
    if (row > 0 && grid[row - 1][col] > 0 && !vis[row - 1][col]) {
        solve(grid, vis, temp, row - 1, col, m, n);
    }
    // Down
    if (row < m - 1 && grid[row + 1][col] > 0 && !vis[row + 1][col]) {
        solve(grid, vis, temp, row + 1, col, m, n);
    }
}

int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0 && !vis[i][j]) {
                int temp = 0; // Reset temp for each connected component
                solve(grid, vis, temp, i, j, m, n);
                ans = max(ans, temp); // Update the maximum fish sum
            }
        }
    }
    return ans;
}


int main(){
    //vector<vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    vector<vector<int>> grid = {{4, 5, 5}, {0, 10, 0}};
    cout<<findMaxFish(grid);
}