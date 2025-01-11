#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

class graph{
    public:
    map<int, list<pair<int,int>>> adj;

    void addEdge(int u,int v,int w,bool direction){
        //direction =0 -> undirected
        //direction =1 -> directed

        //create an edge from u to v
        adj[u].push_back(make_pair(v,w));
        if(direction==0){  //undirected
            adj[v].push_back(make_pair(u,w));
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<" | ";
            for(auto j:i.second){
                cout<<i.first << "-> "<<j.first<<",weight: "<<j.second<<"       ";
            }
            cout<<endl;
        }
    }

    map<int,list<pair<int,int>>> getAdjList(){
        return adj;
    }
};

vector<pair<pair<int,int>,int>> prims(graph g,int n,int src){
    map<int,list<pair<int,int>>> adj=g.getAdjList();
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> mst(n+1);

    for(int i=0;i<=n;i++){  //Initialise all
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    //start the algo
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++){ //for all nodes
        int mini=INT_MAX;
        int u;  //minimum key[] value that is not visited

        //find the mini wali node by traversing key[]
        for(int k=1;k<=n;k++){
            if(mst[k]==false && key[k]<mini){
                u=k;  //u= minimum_node
                mini=key[k];
            }
        }

        //mark min node as true
        mst[u]=true;

        //check its adjacent node
        for(auto it:adj[u]){
            int v=it.first;  //v= neighbour node
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    for(int i=2;i<=n;i++){  //start from 2 as node 1 has parent -1
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));  //parent, node ,weight
    }

    return result;
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
        int u,v;
        cout<<"Enter the edge"<<endl;
        cin>>u>>v;
        int w;
        cout<<"Enter the weight"<<endl;
        cin>>w;
        g1.addEdge(u,v,w,0);  //undirected
    }
    
//5 14 122 146 212 233 248 255 323 357 416 428 459 525 537 549
    vector<pair<pair<int,int>,int>> k=prims(g1,n1,1);
    for(auto i:k){
        cout<<"parent: "<<i.first.first<<" ";
        cout<<"node: "<<i.first.second<<" ";
        cout<<"weight: "<<i.second<<endl;
    }

}