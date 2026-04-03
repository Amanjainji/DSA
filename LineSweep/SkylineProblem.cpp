/*
Problem (Skyline LC-218)

👉 You’re given buildings:

[Li, Ri, Hi]
Li = left
Ri = right
Hi = height

Return the skyline = list of key points where height changes.

🧠 Intuition (VERY IMPORTANT)

Think like sweep line:

When a building starts → height increases
When a building ends → height decreases

👉 At every point:

Track current max height
If it changes → skyline point
💡 Convert to Events

For each building:

(L, -H)  → start (negative for priority)
(R, +H)  → end

👉 Why negative?
So sorting ensures:

Start processed before end
Higher buildings first
⚡ Data Structure

👉 Use multiset / max heap to track active heights

🚀 Algorithm Steps
Convert buildings → events
Sort events
Use multiset:
insert height on start
remove height on end
Track current max height
If height changes → add point
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int,int>> events;

    for (auto &b : buildings) {
        events.push_back({b[0], -b[2]}); // start
        events.push_back({b[1], b[2]});  // end
    }

    sort(events.begin(), events.end());

    multiset<int> heights;  //duplicate elements allowed in sorted order
    heights.insert(0);

    int prevMax = 0;
    vector<vector<int>> ans;

    for (auto &e : events) {
        int x = e.first;
        int h = e.second;

        if (h < 0) {
            heights.insert(-h); // start
        } else {
            heights.erase(heights.find(h)); // end
        }

        int currMax = *heights.rbegin();

        if (currMax != prevMax) {
            ans.push_back({x, currMax});
            prevMax = currMax;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> buildings = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19, 24, 8}
    };

    vector<vector<int>> skyline = getSkyline(buildings);

    for (auto &p : skyline) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }

    return 0;
}