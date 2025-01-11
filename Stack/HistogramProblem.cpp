#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

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
//Leetcode Hard - Histogram
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

int main(){
    vector<int> height={2,3,5,6,2,1};
    cout<<"Largest area is: "<<largestRectangleAreaHistogram(height);
}