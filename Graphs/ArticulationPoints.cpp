#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<int> &result,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    int child=0;
    for(auto nbr: adj[node]){
        if(nbr==parent)
            continue;
        
        //new node find
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node]=min(low[node],low[nbr]);
            //check edge is articulation point 
            if(low[nbr]>=disc[node] && parent!=-1){
                result[node]=1;
            }
            child++;
        }
        else{
           //back edge , already visited and not parent
           low[node]=min(low[node],low[nbr]);
        }
    }

    if(parent==-1 && child>1){
        result[node]=1;
    }
}

vector<int> findArticulationPoints(vector<vector<int>> &edges,int v,int e){
    //adj list
    unordered_map<int ,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent=-1;
    unordered_map<int,bool> vis;

    vector<int> result(v,0);
    //dfs
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);

        }
    }
    return result;
}

int main(){
    vector<vector<int>> edges={{0,1},{0,2},{2,4},{0,3},{2,5},{4,6},{5,6},{2,3}};
    int v=7,e=8;
    vector<int> k=findArticulationPoints(edges,v,e);
    for(int i=0;i<v;i++){
        if(k[i]!=0)
            cout<<i<<" ";  
    }
}