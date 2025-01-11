//To find Strongly connected components
#include<bits/stdc++.h>
using namespace std;

void topo(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){
    vis[node]=true;
    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            topo(nbr,vis,st,adj);
        }
    }
    //topo logic
    st.push(node);
}

void dfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
    vis[node]=true;
    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,adj);
        }
    }
}

int stronglyConnectedComponents(int v,vector<vector<int>> &edges){
    //adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    //topo sort
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,st,adj);
        }
    }

    //create a transpose graph
    unordered_map<int,list<int>> transpose;
    for(int i=0;i<v;i++){
        vis[i]=0;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    //dfs call using above ordering
    int count=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            count++;
            dfs(top,vis,transpose);


        }
    }
    return count;
}

//TC - O(N+E)  SC - O(N+E )
int main(){
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{1,3},{3,4}};
    int v=5;
    cout<<stronglyConnectedComponents(v,edges);
}