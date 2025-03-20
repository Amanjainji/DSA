#include<bits/stdc++.h>
using namespace std;

//find maximum size mountain array

//Longest increasing subsequence optimal
int solveOptimal(vector<int> arr,vector<int> &lis){
    if(arr.size() ==0)
        return 0;

    vector<int> ans;
    lis.push_back(1);
    ans.push_back(arr[0]);

    for(int i=1;i<arr.size();i++){
        if(arr[i]>ans.back()){
            //include
            ans.push_back(arr[i]);
            lis.push_back(ans.size());
        }
        else{
            //overwrite
            //find index of just bada element
            int index=lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[index]=arr[i];
            lis.push_back(index+1); 
        }
    }
    return ans.size();
}

int minimumMountainRemovals(vector<int>&nums) {
    vector<int> lis,lds;
    //make lis and ldr array by taking each element as pivot
    solveOptimal(nums,lis); 
    reverse(nums.begin(),nums.end());
    solveOptimal(nums,lds);

    //main logic
    int largestMountain=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(lis[i]==1 || lds[nums.size()-i-1]==1) continue;
        largestMountain=max(largestMountain,lis[i]+lds[nums.size()-i-1]-1);
    }
    int minRemovals = nums.size() -  largestMountain;
    return minRemovals;
}

int main(){
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout<<minimumMountainRemovals(nums);
}