#include<bits/stdc++.h>
using namespace std;

int binarySearchPivot(vector<int> nums){
    int s=0,e=nums.size()-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(mid!=0 && mid!=nums.size()-1 && nums[mid]<nums[mid-1] && nums[mid+1]>nums[mid])
            return nums[mid];
        else if(nums[mid]>nums[e]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    if(nums[mid]<nums[0])           //  example array - {2,1}
        return nums[mid];
    return nums[0];             // example array - {1,2,3,4,5}
}
int main(){
    vector<int> nums={4,5,1,2,3};
    cout<<binarySearchPivot(nums);
}