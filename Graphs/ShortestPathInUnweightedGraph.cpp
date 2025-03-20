#include<bits/stdc++.h>
using namespace std;

//TC - O(N+E)     SC- O(N+E)
vector<int> shortestPath(vector<vector<int>> &edges,int v,int e,int src,int terminal){
    unordered_map<int, list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v); //undirected
        adj[v].push_back(u);
    }

    //do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    queue<int> q;
    q.push(src);
    parent[src]=-1;
    visited[src]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto i: adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }

    //prepare shortest path
    vector<int> ans;
    int currentNode=terminal;
    ans.push_back(terminal);

    while(currentNode!=src){
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<vector<int>> edges={{1,2},{1,3},{2,5},{3,5},{5,4}};
    int v=5,e=5;
    vector<int> k=shortestPath(edges,v,e,1,4);
    for(auto i:k){
        cout<<i<<" ";
    }
}