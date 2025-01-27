#include<bits/stdc++.h>
using namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    // Step 1: Create adjacency matrix to store prerequisite relationships
    vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
    
    // Step 2: Populate the adjacency matrix from prerequisites
    for (auto& p : prerequisites) {
        isPrerequisite[p[0]][p[1]] = true;
    }
    
    // Step 3: Compute transitive closure using Floyd-Warshall
    for (int k = 0; k < numCourses; ++k) {
        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                isPrerequisite[i][j] = isPrerequisite[i][j] || (isPrerequisite[i][k] && isPrerequisite[k][j]);
            }
        }
    }
    
    // Step 4: Process queries
    vector<bool> ans;
    for (auto& q : queries) {
        ans.push_back(isPrerequisite[q[0]][q[1]]);
    }
    
    return ans;
}

int main(){
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1,2},{1,0},{2,0}}; 
    vector<vector<int>> queries = {{1,0},{1,2}};
    vector<bool> k=checkIfPrerequisite(numCourses,prerequisites,queries);
    for(auto i:k){
        cout<<i<<" ";
    }
}