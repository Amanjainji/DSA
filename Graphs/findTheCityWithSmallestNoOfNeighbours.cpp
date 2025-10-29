#include <bits/stdc++.h>
using namespace std;

//approach
// In order to solve this problem, we will use the Floyd Warshall algorithm (article link of Floyd Warshall). We know Floyd Warshall algorithm helps us to generate a 2D matrix, that stores the shortest distances from each node to every other node. In the generated 2D matrix, each cell matrix[i][j] represents the shortest distance from node i to node j.

// After generating the 2D matrix(that contains the shortest paths) using the Floyd Warshall algorithm, for each node, we will count the number of nodes with a distance lesser or equal to the distanceThreshold by iterating each row of that matrix. Finally, we will choose the node with the minimum number of adjacent cities(whose distance is at the most distanceThreshold) and with the largest value.
class Solution {
public:
	int findCity(int n, vector<vector<int>>& edges,
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) 
			dist[i][i] = 0;

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}
};


int main() {

	int n = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}