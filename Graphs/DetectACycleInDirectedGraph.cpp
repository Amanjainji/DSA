#include<bits/stdc++.h>
using namespace std;

//TC - O(N+E)     SC- O(N+E)
bool topologicalSortBFS(vector<vector<int>> &edges,int v,int e){
    unordered_map<int, list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v); //directed
    }

    //find all indegree 
    vector<int> indegree(v+1,0);
    for(auto i: adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //0 indegree wale ko push krdo
    queue<int> q;
    for(int i=1;i<=v;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    //do bfs
    vector<int> ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
                q.push(neighbour); 
        }
    }
    
    // Check if the graph has a cycle
    if (ans.size() != v) {
        return true;
    }

    return false;
}

int main(){
    vector<vector<int>> edges={{1,2},{2,3},{3,5},{3,4},{4,1},{5,3}};
    int v=5,e=6;
    cout<<topologicalSortBFS(edges,v,e);
}