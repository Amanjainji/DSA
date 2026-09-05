#include<bits/stdc++.h>
using namespace std;

class LogSystem {
public:
    vector<pair<string, int>> logs;

    LogSystem() {}

    void put(int id, string timestamp) {
        logs.push_back({timestamp, id});
    }

    vector<int> retrieve(string start, string end, string granularity) {
        unordered_map<string, int> len = {
            {"Year", 4},
            {"Month", 7},
            {"Day", 10},
            {"Hour", 13},
            {"Minute", 16},
            {"Second", 19}
        };

        int n = len[granularity];

        start = start.substr(0, n);
        end = end.substr(0, n);

        vector<int> ans;

        for (auto &[timestamp, id] : logs) {
            string t = timestamp.substr(0, n);

            if (t >= start && t <= end) {
                ans.push_back(id);
            }
        }

        return ans;
    }
};
