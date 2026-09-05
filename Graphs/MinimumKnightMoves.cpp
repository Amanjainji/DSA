#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        q.push({0, 0});
        visited.insert({0, 0});

        int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [cx, cy] = q.front();
                q.pop();

                if (cx == x && cy == y)
                    return moves;

                for (int i = 0; i < 8; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];

                    // We only need to explore a small region
                    if (nx >= -2 && ny >= -2 &&
                        nx <= x + 2 && ny <= y + 2 &&
                        !visited.count({nx, ny})) {

                        visited.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};