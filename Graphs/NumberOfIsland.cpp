#include<bits/stdc++.h>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

//number of connected componenets question

//bfs
void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<string>> &grid){
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        //treaverse in the neighbours and mark them if its land
        for(int delRow=-1;delRow<=1;delRow++){
            for(int delCol=-1;delCol<=1;delCol++){
                int nrow=row+delRow;
                int ncol=col+delCol;
                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol]=="1" && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int numIslands(vector<vector<string>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && grid[row][col]=="1"){
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<string>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;

    // Loop over 8 directions (including diagonals)
    for (int delRow = -1; delRow <= 1; delRow++) {
        for (int delCol = -1; delCol <= 1; delCol++) {
            int nrow = row + delRow;
            int ncol = col + delCol;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == "1" && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
}

int numIslands2(vector<vector<string>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == "1") {
                cnt++;
                dfs(row, col, vis, grid);
            }
        }
    }

    return cnt;
}

int main(){
    vector<vector<string>> grid = {{"1","1","1","1","0"},{"1","1","0","1","0"},{"1","1","0","0","0"},{"0","0","0","0","0"}};
    cout<<numIslands2(grid);
}