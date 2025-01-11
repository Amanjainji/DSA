#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

class graph{
    public:
    map<int, list<int>> adj;

    void addEdge(int u,int v,bool direction){
        //direction =0 -> undirected
        //direction =1 -> directed

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction==0){  //undirected
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<< i.first << "-> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    map<int,list<int>> getAdjList(){
        return adj;
    }
};
void topoSort_helper(int node,unordered_map<int,bool> &visited,stack<int> &s,map<int,list<int>> &adj){
    visited[node]=1;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort_helper(neighbour,visited,s,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(graph g,int n){
    map<int,list<int>> adj=g.getAdjList();
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i])
            topoSort_helper(i,visited,s,adj);
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main(){
    //directed acyclic graph
    graph g1;
    int n1;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n1;

    int m1;
    cout<<"Enter the number of edges"<<endl;
    cin>>m1;

    //take the edges and node from user
    for(int i=0;i<m1;i++){
        int u,v;
        cin>>u>>v;
        g1.addEdge(u,v,1);  //directed
    }

    vector<int> topo=topologicalSort(g1,n1);
    printVector(topo);

}