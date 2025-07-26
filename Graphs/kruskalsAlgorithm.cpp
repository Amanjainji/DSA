#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}

void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

class graph{
    public:
    vector<vector<int>> adj;

    void addEdge(int u,int v,int w){
        //undirected
        //create an edge from u to v
        vector<int> k={u,v,w};
        adj.push_back(k); 
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i[0]<<",";
            cout<<i[1]<<",weight: "<<i[2]<<"  ";
            }
            cout<<endl;
        }
    

    vector<vector<int>> getAdjList(){
        return adj;
    }
};

void makeSetInitialize(vector<int> &parent,vector<int> &rank,int n){ 
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int> &parent,int node){
    if(parent[node]==node)
        return node;
    
    return parent[node]= findParent(parent,parent[node]); //path compression;
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[u]>rank[v])
        parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int minimumSpanningTrees(graph g,int n){ //return the total weight of minimum spanning tree
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    makeSetInitialize(parent,rank,n);

    vector<vector<int>> edges=g.getAdjList();
    //sort on the basis of weight
    sort(edges.begin(),edges.end(),cmp);  //algorithm library with comparator
    int minWeight=0;

    for(int i=0;i<edges.size();i++){
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];

        if(u!=v){  //not in same component as diffrent parents
            minWeight+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}

int main(){
    graph g1;  //weighted graphs
    int n1;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n1;

    int m1;
    cout<<"Enter the number of edges"<<endl;
    cin>>m1;

    //take the edges and node from user
    for(int i=0;i<m1;i++){
        int u,v,w;
        cout<<"Enter the edge and weight"<<endl;
        cin>>u>>v>>w;
        g1.addEdge(u,v,w);  //undirected
    } 

    //g1.printAdjList();

    //6 9 411 212 323 423 514 435 627 638 549
    int k=minimumSpanningTrees(g1,n1);
    cout<<"Sum of minimum Spanning tree: "<<k<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
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
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}*/