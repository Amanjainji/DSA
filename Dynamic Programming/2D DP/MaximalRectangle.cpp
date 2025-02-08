#include<bits/stdc++.h> 
using namespace std;

/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
*/

vector<int> nextSmallerElementIndex(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElementIndex(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleAreaHistogram(vector<int> &heights){
    int n=heights.size();
    vector<int> next(n);
    next=nextSmallerElementIndex(heights,n);

    vector<int> prev(n);
    prev=prevSmallerElementIndex(heights,n);
    int area=-1;
    for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int newArea=l*b;
        area=max(area,newArea);
    }
    return area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int maxi =INT_MIN;

    vector<int> histogram(matrix[0].size(),0);
    for(int i=0;i<matrix.size();i++){
        //to create histogram array
        for(int j=0;j<histogram.size();j++){
            if(matrix[i][j]=='1')
                histogram[j]++;
            else   
                histogram[j]=0;
        }
        maxi=max(maxi,largestRectangleAreaHistogram(histogram));
    }
    return maxi;
}
