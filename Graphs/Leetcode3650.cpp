#include<bits/stdc++.h>
using namespace std;

vector<int> dijikstra(vector<vector<int>> &edges,int n,int src){
    map<int, list<pair<int,int>>> adj;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int w=i[2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w*2));
    }
    //map<int,list<pair<int,int>>> adj=g.getAdjList();
    vector<int> dist(n,1e9);
    
    set<pair<int,int>> st; //int,int = distance, node

    dist[src]=0;
    st.insert(make_pair(0,src)); //st =set
    while(!st.empty()){
        //fetch top record
        pair<int,int> top=*(st.begin());   // for *value at begin

        int nodeDistance=top.first;
        int topNode= top.second;
        
        //remove top record
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance+neighbour.second < dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));  //find to delete previous data 

                //if record found,then erase it
                if(record!=st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first]=nodeDistance+neighbour.second;

                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    vector<int> path;
    int node = n-1;

    return dist;
}

int solve(vector<vector<int>> &edges,int n){
    vector<int> dist=dijikstra(edges,n,0);
    return dist[n-1];
}