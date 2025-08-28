#include<bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k){
    int n=nums.size(),ans=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            mpp[nums[j]]++;
            if(mpp.size()==k){
                ans++;
            }
        }
        mpp.clear();
    }
    return ans;
}

int solve(vector<int> &nums, int k){
        if(k<0) return 0;
        int l=0, ans=0, r=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                    mpp.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
int subarraysWithKDistinct1(vector<int>& nums, int k) {
    return solve(nums,k) - solve(nums,k-1);
}

int main(){
    vector<int> nums={1,2,1,2,3};
    cout<<subarraysWithKDistinct(nums,2);
}