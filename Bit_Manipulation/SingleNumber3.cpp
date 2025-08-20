#include<bits/stdc++.h>
using namespace std;

/*
Given 
arr={5,5,7,2,4,4};
ans=7,2
*/

//approach-1 TC - O(N*31)
vector<int> singleNumber(vector<int> arr){
    long long xorr=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
        xorr^=arr[i];
    
    int rightmost=(xorr&(xorr-1))^xorr; //rightmost bit that differ in both numbers
    //buckets
    int b1=0,b2=0;
    for(int i=0;i<n;i++){
        if(arr[i]&rightmost) b1=b1^arr[i];
        else 
            b2=b2^arr[i];
    }
    return {b1,b2};
}

int main(){
    vector<int> arr={5,5,3,8,4,4,9,9};
    vector<int> ans=singleNumber(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}