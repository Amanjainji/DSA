#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
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
        if(direction==0) //undirected
            adj[v].push_back(u);
        
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

//BFS Traversal

//algorithm
/*

1) Declare a queue q, a visited[] map,and a variable frontnode
2)take out node data in frontnode from queue
3)pop the queue
4)make visited column true for node
5)store the answer of frontnode
6)all the adjacent of frontnode push into queue , push only if visited[] is false
 
*/
void bfsSolve(map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node);

vector<int> BFS(graph g,int vertex){  //total nodes as graph can be disconnected
    map<int,list<int>> adj=g.getAdjList();
    vector<int> ans;
    unordered_map<int,bool> visited;

    //traverse all components of a disconnected graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfsSolve(adj,visited,ans,i);
        }
    }

    return ans;
}
void bfsSolve(map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;  //for source node

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        //store frontNode to ans
        ans.push_back(frontNode);

        //traverse all neighbors of frontNode
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;  //for all remaining nodes
            } 
        }
    }   
}


//DFS 
void dfshelper(int node, unordered_map<int,bool> &visited,map<int,list<int>> &adjList,vector<int> &component);

vector<vector<int>> depthFirstSearch(graph g,int V){  //V= total vertex , E= total edges
    map<int,list<int>> adj=g.getAdjList();
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfshelper(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

void dfshelper(int node, unordered_map<int,bool> &visited,map<int,list<int>> &adj,vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    //hr connected node ke liye recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfshelper(i,visited,adj,component);
        }
    }
}

//cycle detection
bool isCycleBFS_helper(int src,unordered_map<int,bool> &visited,map<int,list<int>> &adj);

bool cycleDetectionBFS(graph g,int n){
    map<int,list<int>> adj=g.getAdjList();
    unordered_map<int,bool> visited;
    bool ans;
    for(int i=1;i<=n;i++){  //for disconnected nodes
        if(!visited[i]){
            ans=isCycleBFS_helper(i,visited,adj);
            if(ans==1){
                return true;
            }   
        } 
    }
    return false;
}

bool isCycleBFS_helper(int src,unordered_map<int,bool> &visited,map<int,list<int>> &adj){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour:adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front])   // neighbour jo hai wo visited hai but parent nhi hai toh cycle
                return true;

            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

bool isCycleDFS_helper(int node,int parent,unordered_map<int,bool> &visited,map<int,list<int>> &adj){
    visited[node] = true;  // Mark the current node as visited
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){  // not visited yet
            bool cycleDetected=isCycleDFS_helper(neighbour,node,visited,adj);
            if(cycleDetected)
                return true;
        }
        else if(neighbour!=parent){   // visited hai then condn
            return true;
        }
    }
    return false; 
}

bool cycleDetectionDFS(graph g,int n){
    map<int,list<int>> adj=g.getAdjList();
    unordered_map<int,bool> visited;
    for(int i=1;i<=n;i++){  //for disconnected nodes
        if(!visited[i]){
            bool ans=isCycleDFS_helper(i,-1,visited,adj);
            if(ans){
                return true;
            }   
        }
    }
    return false;
}

//Directed graph cycle
bool checkCycleDFS_helper(int node ,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,map<int,list<int>> &adj){
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected=checkCycleDFS_helper(neighbour,visited,dfsvisited,adj);   //DFS Recursion
            if(cycleDetected){
                return true;
            }
        }
        else if(visited[neighbour]==true && dfsvisited[neighbour]==true){  //imp condn
            return true;
        }
    }
    dfsvisited[node]=false;  // jaate jaate false mark krkr jayenge
    return false;
}

int detectCycleInDirectedGraph(graph g,int n){
    map<int,list<int>> adj=g.getAdjList();
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycleFound= checkCycleDFS_helper(i,visited,dfsvisited,adj);
            if(cycleFound)
                return true;
        }
    }
    return false;
}

int main(){
/*
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    // 5 6 0 1 1 2 2 3 3 4 3 1 4 0
    graph g;
    //take the edges and node from user
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);  //undirected
    }
*/
    //g.printAdjList();

    //vector<int> ans=BFS(g,5);
    //printVector(ans);

/*
    vector<vector<int>> ans1=depthFirstSearch(g,5);   //{{0,1,2,3,4}}
    cout<<endl;
    for(auto i:ans1){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
*/

//cycle detection using BSF
//disconnected graph - 9 8 1 2 2 3 4 5 5 6 5 7 6 8 7 8 8 9

//cout<<cycleDetectionBFS(g,n);
//cout<<cycleDetectionDFS(g,n);


//Directed graphs : 

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

    //8 9 1 2 2 3 3 7 3 8 8 7 2 4 4 5 5 6 6 4
    cout<<detectCycleInDirectedGraph(g1,n1);

}

