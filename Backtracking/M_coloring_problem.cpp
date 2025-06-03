#include<bits/stdc++.h>
using namespace std;
/*
Given an edges of graph and a number m, the your task is to find weather is possible to color the given graph with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

Examples

Input: V = 4, edges[][] = [[0, 1], [0, 2], [0,3], [1, 3], [2, 3]], m = 3
Output: true
Explanation: Structure allows enough separation between connected vertices, so using 3 colors is sufficient to ensure no two adjacent vertices share the same color—hence, the answer is true
*/

//make adjacency list of graph
map<int,vector<int>> getAdjacencyList(vector<vector<int>> &edges){
    map<int,vector<int>> ans;
    for(auto edge:edges){
        ans[edge[0]].push_back(edge[1]);
        ans[edge[1]].push_back(edge[0]);
    }
    return ans;
}

bool isSafe(int i,int node,map<int,vector<int>> &list,vector<int> &color){
    for(auto neighbour:list[node]){
        if(color[neighbour]==i) return false;
    }
    return true;
}
bool solve(int node,int n,int m,map<int,vector<int>> &list,vector<int> &color){
    if(node==n)
        return true;
    for(int i=1;i<=m;i++){
        if(isSafe(i,node,list,color)){
            color[node]=i;
            if(solve(node+1,n,m,list,color)) return true;
            color[node]=0;      //backtrack
        }
    }
    return false;
}
int main(){
    int n=4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0,3}, {1, 3}, {2, 3}};
    int m = 3;
    vector<int> color(n,0);
    map<int,vector<int>> list=getAdjacencyList(edges);
    cout<< solve(0,n,m,list,color);
}