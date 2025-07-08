#include<bits/stdc++.h>
using namespace std;

    // Binary search to find the next event starting after current end time
    int binarySearch(vector<vector<int>>& events, int i, int endTime) {
        int low = i, high = events.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > endTime) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<vector<int>> dp;

    int solve(int i, vector<vector<int>>& events, int k) {
        if (i == events.size() || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int exclude = solve(i + 1, events, k);

        int next = binarySearch(events, i + 1, events[i][1]);
        int include = events[i][2];
        if (next != -1)
            include += solve(next, events, k - 1);

        return dp[i][k] = max(include, exclude);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return solve(0, events, k);
    }


int main(){
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    cout<<maxValue(events,2);
}

