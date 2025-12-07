/*
Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
     i.  Each student gets exactly one packet.
     ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

Examples:

Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
*/

#include<bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> a,int m){       //n packets, m student
    sort(a.begin(),a.end());
    int i=0;
    int j=m-1;

    int mini=INT_MAX;
    while(j<a.size()){
        int diff=a[j]-a[i];
        mini=min(mini,diff);
        i++;
        j++;
    }
    return mini;
}

int main(){
    vector<int> chocolates={3, 4, 1, 9, 56, 7, 9, 12};
    cout<<findMinDiff(chocolates,5);
}