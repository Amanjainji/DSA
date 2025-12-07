/*
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
*/
#include<bits/stdc++.h>
using namespace std;
int minCost(vector<int> ropes){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<ropes.size();i++){
        minHeap.push(ropes[i]);
    }
    int cost=0;
    while(minHeap.size()>1){
        int min1=minHeap.top();
        minHeap.pop();
        int min2=minHeap.top();
        minHeap.pop();
        int sum=min1+min2;
        cost+=sum;
        minHeap.push(sum);
    }

    return cost;
}

int main(){
    vector<int> ropes={4, 3, 2, 6};
    cout<<minCost(ropes);
}