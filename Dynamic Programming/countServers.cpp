#include<bits/stdc++.h>
using namespace std;

int countServers(vector<vector<int>>& grid) {
    vector<pair<int,int>> v;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                v.push_back({i,j});
            }
        }
    }
    int ans=0;
    int size=v.size();

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j==i){
                continue;
            }
            else if(v[i].first==v[j].first || v[i].second==v[j].second){
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout<<countServers(grid);
}