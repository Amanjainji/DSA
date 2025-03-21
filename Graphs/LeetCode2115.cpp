#include<bits/stdc++.h>
using namespace std;

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string,vector<string>> graph; // ingredient[i][j] --> vector of recipes they are making
    unordered_map<string,int> indegree;     //  recipies[i] --> count of items they required to made

    //initialize graph and map
    for(int i = 0;i<recipes.size();i++){
        for(string str: ingredients[i]){
            graph[str].push_back(recipes[i]);
            indegree[recipes[i]]++;
        }
    }
    //queue for bfs on supplies
    queue<string> q;
    for(string sup: supplies){
        q.push(sup);
    }
    vector<string> ans;
    //BFS
    while(!q.empty()){
        string item = q.front();
        q.pop();
        for(string nextRecipe: graph[item]){
            indegree[nextRecipe]--;
            if(indegree[nextRecipe]==0){
                ans.push_back(nextRecipe);
                q.push(nextRecipe);
            }
        }
    }
    return ans;
}

int main(){
    vector<string> recipes={"bread","sandwich","burger"};
    vector<vector<string>> ingredients={{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> supplies={"yeast","flour","meat"};
    vector<string> ans=findAllRecipes(recipes,ingredients,supplies);
    for(auto i:ans){
        cout<<i<<"  ";
    }
}