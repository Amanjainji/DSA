#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<pair<int,int>> events;

    for (auto &it : intervals) {
        events.push_back({it[0], 1});   // start
        events.push_back({it[1], -1});  // end
    }

    // IMPORTANT: end first if same time
    sort(events.begin(), events.end(), [](auto &a, auto &b){
        if (a.first == b.first)
            return a.second < b.second; // -1 before +1
        return a.first < b.first;
    });

    int active = 0, rooms = 0;

    for (auto &e : events) {
        active += e.second;
        rooms = max(rooms, active);
    }

    return rooms;
}

int minMeetingRooms2(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto &it : intervals) {
        if (!pq.empty() && pq.top() <= it[0]) {
            pq.pop(); // reuse room
        }
        pq.push(it[1]);
    }

    return pq.size();
}

int main() {
    vector<vector<int>> intervals = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    cout << "Minimum Meeting Rooms: "<< minMeetingRooms2(intervals) << endl;

    return 0;
}