#include <bits/stdc++.h>
using namespace std;

int maxOverlap(vector<vector<int>>& intervals) {
    vector<pair<int,int>> events;

    for (auto &it : intervals) {
        events.push_back({it[0], 1});   // start
        events.push_back({it[1], -1});  // end
    }

    sort(events.begin(), events.end(), [](auto &a, auto &b){
        if (a.first == b.first)
            return a.second < b.second; // end before start
        return a.first < b.first;
    });

    int active = 0, ans = 0;

    for (auto &e : events) {
        active += e.second;
        ans = max(ans, active);
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 5},
        {2, 6},
        {4, 8},
        {7, 9}
    };

    cout << "Maximum Overlap: " << maxOverlap(intervals) << endl;

    return 0;
}