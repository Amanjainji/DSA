#include<bits/stdc++.h>
using namespace std;
//2d dp concept question

/*
Problem statement:
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
*/

//Recursive  TC - O(expo^N)   SC -O(N*W)
int solve(vector<int> &weight,vector<int> &value,int index,int capacity){
    //base case
    //(if only 1 item to steal,then just compare its weight with the knapsack capacity)
    if(index==0){
        if(weight[0]<=capacity)
            return value[0];
        else{
            return 0;
        }
    }

    int include=0;
    if(weight[index]<=capacity)
        include=value[index]+solve(weight,value,index-1,capacity-weight[index]);

    int exclude= 0 + solve(weight,value,index-1,capacity);
    int ans=max(exclude,include);
    return ans;
}

int knapSack(vector<int> weight,vector<int> value,int n,int maxCapacity){
    return solve(weight,value,n-1,maxCapacity);
}

//Recursive + memoization TC - O(N*W)   SC -O(N*W)
int solve2(vector<int> &weight,vector<int> &value,int index,int capacity,vector<vector<int>> &dp){
    //base case
    //(if only 1 item to steal,then just compare its weight with the knapsack capacity)
    if(index==0){
        if(weight[0]<=capacity)
            return value[0];
        else{
            return 0;
        }
    }

    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }

    int include=0;
    if(weight[index]<=capacity)
        include=value[index]+solve2(weight,value,index-1,capacity-weight[index],dp);

    int exclude=solve2(weight,value,index-1,capacity,dp);
    dp[index][capacity]=max(exclude,include);
    return dp[index][capacity];
}

int knapSack2(vector<int> weight,vector<int> value,int n,int maxCapacity){
    vector<vector<int>> dp(n,vector<int>(maxCapacity+1,-1));
    return solve2(weight,value,n-1,maxCapacity,dp);
}

//Bottom Up approach - TC - O(N*W)   SC -O(N*W)
int knapSack3(vector<int> weight,vector<int> value,int n,int capacity){
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    //base case analysis
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity)
            dp[0][w]=value[0];
        else    
            dp[0][w]=0;
    }
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;
            if(weight[index]<=w)
                include=value[index]+dp[index-1][w-weight[index]];

            int exclude=dp[index-1][w];
            dp[index][w]=max(exclude,include);
        }
    }  
    return dp[n-1][capacity];
}

//Space Optimization - TC - O(N*W)   SC -O(2*W)
int knapSack4(vector<int> weight,vector<int> value,int n,int capacity){
    //step 1:
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);

    //step 2: analyse base case
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity)
            prev[w]=value[0];
        else    
            prev[w]=0;
    }
    //step 3
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;
            if(weight[index]<=w)
                include=value[index]+prev[w-weight[index]];

            int exclude=prev[w];
            curr[w]=max(exclude,include);
        }
        prev=curr; //increment prev
    }  
    return prev[capacity];
}

//Optimized Space Optimization - TC - O(N*W)   SC -O(W)  (No use of prev vector)
int knapSack5(vector<int> weight,vector<int> value,int n,int capacity){
    //step 1:
    vector<int> curr(capacity+1,0);

    //step 2: analyse base case
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity)
            curr[w]=value[0];
        else    
            curr[w]=0;
    }
    //step 3
    for(int index=1;index<n;index++){
        for(int w=capacity;w>=0;w--){   //Imp. step
            int include=0;
            if(weight[index]<=w)
                include=value[index]+curr[w-weight[index]];

            int exclude=curr[w];
            curr[w]=max(exclude,include);
        }
    }  
    return curr[capacity];
}

int main(){
    vector<int> weight={1,2,4,5};
    vector<int> value={5,4,8,6};
    cout<<knapSack5(weight,value,4,5);
}