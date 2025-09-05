#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        int n=interval.size();
        while(i<n && interval[i][1]<newInterval[0]){
            ans.push_back(interval[i]);
            i++;
        }
        while(i<n && interval[i][0]<=newInterval[1]){
            newInterval[0]=min(interval[i][0],newInterval[0]);
            newInterval[1]=max(interval[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(interval[i]);
            i++;
        }
        return ans;     
    }
};