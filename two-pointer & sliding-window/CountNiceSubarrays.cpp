#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size();
        int l=0,r=0,odds=0,ans=0;
        while(r<n){
            if(nums[r]%2!=0) odds++;
            while(odds>k){
                if((nums[l]%2)==1)
                    odds--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }

int numberOfSubarrays(vector<int>& nums, int k) {
    return solve(nums,k) - solve(nums,k-1);
}

int main(){
    vector<int> nums={1,1,2,1,1};
    cout<<numberOfSubarrays(nums,3);
}