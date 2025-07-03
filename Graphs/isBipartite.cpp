#include<bits/stdc++.h>
using namespace std;

//using BFS
bool isBipartiteBFShelper(int node,vector<vector<int>>& graph,unordered_map<int,bool> &visited,vector<int> &colors){
        queue<int> q;
        q.push(node);
        colors[node]=0;
        visited[node]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto neighbour:graph[front]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    if(colors[front]==0)
                        colors[neighbour]=1;
                    else
                        colors[neighbour]=0;
                    q.push(neighbour);
                }
                else if(colors[front]==colors[neighbour]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       unordered_map<int,bool> visited;
       vector<int> colors(graph.size(),-1);
       for(int i=0;i<graph.size();i++){
        if(!visited[i]){
            bool temp=isBipartiteBFShelper(i,graph,visited,colors);
            if(!temp)
                return false;
        }
       }
       return true;
    }


//using DFS
 bool isBipartiteDFShelper(int node,vector<vector<int>>& graph,unordered_map<int,bool> &visited,vector<int> &colors){
        visited[node]=true;
        for(auto neighbour:graph[node]){
            if(!visited[neighbour]){
                if(colors[node]==0)
                    colors[neighbour]=1;
                else
                    colors[neighbour]=0;
                if(!isBipartiteDFShelper(neighbour,graph,visited,colors))
                    return false;
            }
            else if(colors[node]==colors[neighbour]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite2(vector<vector<int>>& graph) {
       unordered_map<int,bool> visited;
       vector<int> colors(graph.size(),-1);
       for(int i=0;i<graph.size();i++){
        if(!visited[i]){
            colors[i]=0;
            bool temp=isBipartiteDFShelper(i,graph,visited,colors);
            if(!temp)
                return false;
        }
       }
       return true;
    }

int main(){
    vector<vector<int>> g={{1,2,3},{0,2},{0,1,3},{0,2}};
    cout<<isBipartite(g);
}