#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<set>
#include<stack>
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

vector<int> dijikstra(graph g,int n,int src){
    map<int,list<pair<int,int>>> adj=g.getAdjList();
    vector<int> dist(n);
    for(int i=0;i<n;i++)  //Initialize all to infinite value
        dist[i]=INT_MAX;
    
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
    return dist;
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
    //cout<<"\n\nAdjacency list is:"<<endl;
    //g1.printAdjList();

    vector<int> k=dijikstra(g1,4,0);
    printVector(k);  
    /*
    4 
    5 
    0 1 5
    0 2 8
    1 2 9
    1 3 2
    2 3 6 
    */
}