#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Edge case: empty input
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        
        // If grid is too small (less than 3x3), no water can be trapped
        if (m < 3 || n < 3) return 0;

        // Each entry in PQ: (height, row, col)
        using T = tuple<int,int,int>;
        // Min-heap based on cell height
        priority_queue<T, vector<T>, greater<T>> pq;
        
        // Track visited cells to avoid re-processing
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the priority queue
        // Left and right columns
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i, 0);     visited[i][0] = true;
            pq.emplace(heightMap[i][n-1], i, n-1); visited[i][n-1] = true;
        }
        // Top and bottom rows
        for (int j = 0; j < n; ++j) {
            if (!visited[0][j]) { 
                pq.emplace(heightMap[0][j], 0, j); 
                visited[0][j] = true; 
            }
            if (!visited[m-1][j]) { 
                pq.emplace(heightMap[m-1][j], m-1, j); 
                visited[m-1][j] = true; 
            }
        }

        int res = 0; // total trapped water
        // 4 directions: down, up, right, left
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        // Process cells in order of their boundary height
        while (!pq.empty()) {
            auto cur= pq.top(); 
            pq.pop();
            int h = get<0>(cur);
            int r = get<1>(cur);
            int c = get<2>(cur);

            // Explore all 4 neighbors
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                
                // Skip out-of-bounds or already visited
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) 
                    continue;
                
                visited[nr][nc] = true;
                int nh = heightMap[nr][nc]; // neighbor's ground height

                // If neighbor is lower than current boundary,
                // water is trapped = boundary - neighbor height
                if (nh < h) res += h - nh;

                // Push the neighbor with updated effective boundary:
                // - if higher than current boundary, keep its own height
                // - if lower, water fills it up to boundary height
                pq.emplace(max(nh, h), nr, nc);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> heightMap={{3,3,3,3},{3,2,2,3},{3,2,2,3},{3,3,3,3}};
    Solution s;
    cout<<s.trapRainWater(heightMap);
}
