//dijikstra is not used for negative weights
//it can also be used to detect negative cycles

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n,int m,int src, vector<vector<int>> &edges){
    vector<int> dist(n+1,1e9);  //assuming nodes starting from 1 so n+1 ,1e9 for infinity
    dist[src]=0;

    for(int i=1;i<=n;i++){  //n-1 times
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }

    //check for negative cycles
    bool flag=0;
    for(int j=0;j<m;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];

        if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
            flag=1;
        }
    }
    if(flag==1){
        cout<<"Negative cycle is present "<<endl;
        return {};
    }
    return dist;
}


//TC - O(N*E)    SC - O(1)
int main(){
    vector<vector<int>> edges={{1,2,2},{2,3,-1},{1,3,2}};
    int v=3,e=3;
    vector<int> k=bellmonFord(v,e,1,edges);
    cout<<k[3]<<endl; 
    //3 node distance must be 1 (2+(-1))  not 2
}