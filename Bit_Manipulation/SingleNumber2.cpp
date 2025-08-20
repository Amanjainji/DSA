#include<bits/stdc++.h>
using namespace std;

/*
Given 
arr={5,5,5,2,4,4,4};
ans=2
*/

//approach-1 TC - O(N*31)
int singleNumber(vector<int> arr){
    int ans=0;
    int n=arr.size();
    for(int bit=0;bit<31;bit++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]& (1<<bit))
                cnt++;
        }
        if(cnt%3==1)
            ans=ans|(1<<bit);
    }
    return ans;
}

int singleNumber2(vector<int> nums){
    int ones=0;
    int twos=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        ones=(ones^nums[i])& ~twos;
        twos=(twos^nums[i])& ~ones;
    }
    return ones;
}


int main(){
    vector<int> arr={5,5,5,2,4,4,4};
    cout<<singleNumber2(arr)<<endl;
}