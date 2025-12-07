/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

Example 1:

Input:
N = 6
S = {1,3,0,5,8,5}
F = {2,4,6,7,9,9} 

Output:
{1,2,4,5}
*/

#include <bits/stdc++.h>
using namespace std;

    static bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        // Sort by end time; if end times are the same, sort by the original index
        if (a.first.second == b.first.second) {
            return a.first.second-a.first.first < b.first.second - b.first.second;
        }
        return a.first.second < b.first.second;
    }

    vector<int> maxMeetings(int n, int start[], int end[]) {
        // Create a vector of pairs where each pair contains (start, end) and its original index
        vector<pair<pair<int, int>, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({{start[i], end[i]}, i + 1}); // Store 1-based index
        }

        // Sort meetings by their end time 
        sort(meetings.begin(), meetings.end(), cmp);

        vector<int> result;
        int lastEnd = -1; // Tracks the end time of the last selected meeting

        for (int i = 0; i < n; i++) {
            if (meetings[i].first.first > lastEnd) { // If the start time is after the last end time
                result.push_back(meetings[i].second); // Add the meeting's original index
                lastEnd = meetings[i].first.second; // Update the last end time
            }
        }

        sort(result.begin(),result.end());
        return result;
    }


int main(){
    int start[]={12 ,6, 16, 12, 6, 9, 16, 6, 17, 5};
    int end[]={17, 13, 16, 18, 17, 10, 18, 12, 18, 11};
    vector<int> ans=maxMeetings(10,start,end);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}