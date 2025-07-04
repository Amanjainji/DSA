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