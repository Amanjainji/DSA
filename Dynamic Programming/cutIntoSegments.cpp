#include<bits/stdc++.h>
using namespace std;

//Recursion
int cutIntoSegmentsRec(int n,int x,int y ,int z){
    //base case
    if(n==0)
        return 0;
    if(n<0)
        return INT_MIN;
    
    int a=cutIntoSegmentsRec(n-x,x,y,z)+1;
    int b=cutIntoSegmentsRec(n-y,x,y,z)+1;
    int c=cutIntoSegmentsRec(n-z,x,y,z)+1;

    int ans=max(a,max(b,c));
    return ans;
}

int cutIntoSegments(int n,int x,int y ,int z){
    int ans=cutIntoSegmentsRec(n,x,y,z);
    if(ans<0)
        return 0;
    return ans;
}

//Top-Bottom Approach (Recursion + Memoization)
int cutIntoSegmentsMem(int n,int x,int y ,int z,vector<int> &dp){
    //base case
    if(n==0)
        return 0;
    if(n<0)
        return INT_MIN;

    if(dp[n]!=-1)
        return dp[n];
    
    int a=cutIntoSegmentsMem(n-x,x,y,z,dp)+1;
    int b=cutIntoSegmentsMem(n-y,x,y,z,dp)+1;
    int c=cutIntoSegmentsMem(n-z,x,y,z,dp)+1;

    dp[n]=max(a,max(b,c));
    return dp[n];
}

int cutIntoSegments2(int n,int x,int y ,int z){
    vector<int> dp(n+1,-1);
    int ans=cutIntoSegmentsMem(n,x,y,z,dp);
    if(ans<0)
        return 0;
    return ans;

}

//Bottom-Up Approach (Tabulation)
int cutIntoSegments3(int n,int x,int y ,int z){
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i-x>=0)
            dp[i]=max(dp[i],dp[i-x]+1);
        if(i-y>=0)
            dp[i]=max(dp[i],dp[i-y]+1);
        if(i-z>=0)
            dp[i]=max(dp[i],dp[i-z]+1);
    }

    if(dp[n]<0)
        return 0;
    return dp[n];
}


int main(){
    cout<<cutIntoSegments3(8,3,3,2);
}