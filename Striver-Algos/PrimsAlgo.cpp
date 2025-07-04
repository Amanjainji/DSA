#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void printMST(vector<vector<int>> &MST){
		cout<<"{ ";
		for(auto i:MST){
			cout<<"("<<i[0]<<","<<i[1]<<")"<<" ";
		}
		cout<<"}"<<endl;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>> >, greater<pair<int, pair<int,int>>>> pq;
		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, {0,-1}}); //weight , <node, parent>
		int sum = 0;
		vector<int> parent(V,-1);
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second.first;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			parent[node]=it.second.second;
			sum += wt;
			for (auto neighbour : adj[node]) {
				int adjNode = neighbour[0];
				int neighbourWeight = neighbour[1];
				if (!vis[adjNode]) {
					pq.push({neighbourWeight, {adjNode,node}});
				}
			}
		}
		vector<vector<int>> MST;
		for(int i=1;i<V;i++){
			MST.push_back({parent[i],i});
		}
		printMST(MST);
		
		return sum;
	}
};


int main() {

	int V = 5;
	vector<vector<int>> edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}