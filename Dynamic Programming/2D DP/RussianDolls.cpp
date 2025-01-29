#include<bits/stdc++.h>
using namespace std;

/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/
static bool cmp(vector<int> &a,vector<int> &b){
    if(a[0]==b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}

int Lis(int n,vector<int> &a){
    if(n==0)
        return 0;
    
    vector<int> ans;
    ans.push_back(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]> ans.back())
            ans.push_back(a[i]);
        else{
            //find index of just bada element in ans
            int index=lower_bound(ans.begin(),ans.end(),a[i]) -ans.begin();
            ans[index]=a[i];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    //sort the envelopes  
    sort(envelopes.begin(),envelopes.end(),cmp);
    //use lis on the height of the envelopes
    vector<int> heights;
    for(auto i:envelopes){
        heights.push_back(i[1]);
    }
    return Lis(heights.size(),heights);
}

int main(){
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout<<maxEnvelopes(envelopes);
}