#include <bits/stdc++.h>
using namespace std;

pair<int, int> source, destination;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid){
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},
                                {1,1},{1,-1},{-1,1},{-1,-1}};
    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0] = 1; 
    while (!q.empty()) {
        pair<int,int> rc = q.front(); q.pop();
        int r=rc.first;
        int c=rc.second;
        int dist = grid[r][c];
        if (r == n-1 && c == n-1) return dist;

        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0) {
                grid[nr][nc] = dist + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;

    }
};

int main()
{   source.first = 0;
    source.second = 0;
    destination.first = 3;
    destination.second = 3;
    // Driver Code.
    vector<vector<int>> grid = {{0, 1, 1, 1},
                                {1, 0, 0, 1},
                                {1, 1, 1, 0},
                                {1, 1, 0, 0},
                                };

    Solution obj;

    int res = obj.shortestPath(grid);

    cout << res;
    cout << endl;

    return 0;
}