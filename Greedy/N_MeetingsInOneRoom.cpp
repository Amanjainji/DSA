/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example
Input: start[] = [1, 3, 0, 5, 8, 5],
    end[] =  [2, 4, 6, 7, 9, 9];
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

*/

#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int maxMeetings(int start[],int end[],int n){
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        pair<int,int> p=make_pair(start[i],end[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);
    int count=1;
    int ansEnd=v[0].second;

    for(int i=1;i<n;i++){
        if(v[i].first>ansEnd){
            count++;
            ansEnd=v[i].second;
        }
    }
    return count;    
}

int main(){
    int start[]={1, 3, 0, 5, 8, 5};
    int end[]={2, 4, 6, 7, 9, 9};
    cout<<maxMeetings(start,end,6);
}