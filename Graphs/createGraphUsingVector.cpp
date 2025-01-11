#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> edges){
    //n = no. of nodes and m=no. of edges
    vector<int> ans[n]; //ans array will store all adjacent nodes corresponding on index
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);  //as graph is undirected
    }

    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

void print(vector<vector<int>> arr){
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> uv={{0,1},{1,2},{2,3},{3,4},{4,0},{3,1}};
    vector<vector<int>> ans=printAdjacency(5,6,uv);
    print(ans);
}

