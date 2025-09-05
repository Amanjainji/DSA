#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, visited, path, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            // Skip already visited
            if (visited[i]) continue;
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue; //Always pick duplicates in the same relative order they appear in the sorted array.
            
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, visited, path, res);
            path.pop_back();
            visited[i] = false;
        }
    }
};
