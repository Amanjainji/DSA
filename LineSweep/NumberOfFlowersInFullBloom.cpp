#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector<int> start, end;
        
        for(auto &f : flowers){
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        vector<int> ans;
        
        for(int t : people){
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            /*
            Meaning:

            Count how many flowers have start ≤ t

            Why upper_bound?
            upper_bound(t) gives first element > t
            So everything before it is ≤ t
            */
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            /*
            Meaning:

            Count how many flowers have end < t

            Why lower_bound?
            lower_bound(t) gives first element ≥ t
            So everything before it is < t
            */            
            ans.push_back(started - ended);
        }
        
        return ans;
    }
    //line sweep
    vector<int> fullBloomFlowers2(vector<vector<int>>& flowers, vector<int>& people) {
        
        map<int,int> events;
        
        for(auto &f : flowers){
            events[f[0]]++;
            events[f[1] + 1]--;
        }
        
        vector<pair<int,int>> sortedPeople;
        for(int i = 0; i < people.size(); i++){
            sortedPeople.push_back({people[i], i});
        }
        
        sort(sortedPeople.begin(), sortedPeople.end());
        
        vector<int> ans(people.size());
        int curr = 0;
        auto it = events.begin();
        
        for(auto &[time, idx] : sortedPeople){
            
            while(it != events.end() && it->first <= time){
                curr += it->second;
                it++;
            }
            
            ans[idx] = curr;
        }
        
        return ans;
    }
};