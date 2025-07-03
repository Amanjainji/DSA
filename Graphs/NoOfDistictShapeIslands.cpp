#include<bits/stdc++.h>
using namespace std;


        void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &shape, int baseRow, int baseCol) {
            int n = grid.size();
            int m = grid[0].size();
            vis[row][col] = 1;
            shape.push_back({row - baseRow, col - baseCol});
    
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            
            for (int i = 0; i < 4; ++i) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    dfs(newRow, newCol, vis, grid, shape, baseRow, baseCol);
                }
            }
        }
    
        int countDistinctIslands(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m, 0));
            set<vector<pair<int, int>>> uniqueIslands;
    
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < m; ++col) {
                    if (!vis[row][col] && grid[row][col] == 1) {
                        vector<pair<int, int>> shape;
                        dfs(row, col, vis, grid, shape, row, col);
                        uniqueIslands.insert(shape);
                    }
                }
            }/*
            for(auto i:uniqueIslands){
                for(auto j:i){
                    cout<<j.first<<","<<j.second<<" ";
                }
                cout<<endl;
            }*/
            return uniqueIslands.size();
        }

        int main(){
            vector<vector<int>> grid= {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}};
            cout<<countDistinctIslands(grid);

        }