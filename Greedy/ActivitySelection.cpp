/*
Given some activities with their start and end day given in array start[] and end[]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
*/

#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int activitySelection(vector<int> &start, vector<int> &end){
    vector<pair<int,int>> v;
    for(int i=0;i<start.size();i++){
        v.push_back(make_pair(start[i],end[i]));
    }
    sort(v.begin(),v.end(),cmp);
    int count=1;
    int lastEnd=v[0].second;
    for(int i=1;i<v.size();i++){
        if(v[i].first>lastEnd){
            count++;
            lastEnd=v[i].second;
        }
    }
    return count;
}

int main(){
    vector<int> start = {1, 3, 2, 5}, end = {2, 4, 3, 6};
    cout<<activitySelection(start,end);
}