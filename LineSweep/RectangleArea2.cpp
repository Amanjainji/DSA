#include <bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
int rectangleArea(vector<vector<int>>& rectangles) {
    vector<tuple<int,int,int,int>> events;

    // Step 1: Create events
    for (auto &r : rectangles) {
        events.push_back({r[0], 1, r[1], r[3]});  // entering
        events.push_back({r[2], -1, r[1], r[3]}); // leaving
    }

    // Step 2: Sort by x
    sort(events.begin(), events.end());

    vector<pair<int,int>> active; // active y-intervals
    int prevX = get<0>(events[0]);
    long long area = 0;

    for (auto &[x, type, y1, y2] : events) {

        // Step 3: Compute total y coverage
        int y_coverage = 0;

        if (!active.empty()) {
            vector<pair<int,int>> temp = active;

            sort(temp.begin(), temp.end());

            int start = temp[0].first, end = temp[0].second;

            for (auto &[l, r] : temp) {
                if (l > end) {
                    y_coverage += end - start;
                    start = l;
                    end = r;
                } else {
                    end = max(end, r);
                }
            }
            y_coverage += end - start;
        }

        // Step 4: Add area
        area += 1LL * (x - prevX) * y_coverage;

        // Step 5: Update active intervals
        if (type == 1) {
            active.push_back({y1, y2});
        } else {
            // remove one occurrence
            auto it = find(active.begin(), active.end(), make_pair(y1, y2));
            if (it != active.end()) active.erase(it);
        }

        prevX = x;
    }

    return area%mod;
}