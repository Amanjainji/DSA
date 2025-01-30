#include<bits/stdc++.h>
using namespace std;

/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
*/

//similar to house robbery problem
int solve(int index,int endIndex,vector<int> &slices,int n){
    //base case
    if(n==0 || index>endIndex){
        return 0;
    }

    int take= slices[index]+ solve(index+2 , endIndex,slices,n-1);
    int notTake=0 + solve(index+1,endIndex,slices,n);
    return max(take,notTake);
}

int maxSizeSlices(vector<int> &slices){
    int size=slices.size();
    int case1= solve(0,size-2,slices,size/3);  //not taking last index
    int case2=solve(1,size-1,slices,size/3);
    return max(case1,case2);
}

//Top Down approach
int solveMem(int index,int endIndex,vector<int> &slices,int n,vector<vector<int>> &dp){
    //base case
    if(n==0 || index>endIndex){
        return 0;
    }
    
    if(dp[index][n] !=-1){
        return dp[index][n];
    }

    int take= slices[index]+ solveMem(index+2 , endIndex,slices,n-1,dp);
    int notTake=0 + solveMem(index+1,endIndex,slices,n,dp);
    return dp[index][n]=max(take,notTake);
}

int maxSizeSlicesMem(vector<int> &slices){
    int size=slices.size();

    vector<vector<int>> dp1(size,vector<int>(size,-1));
    int case1= solveMem(0,size-2,slices,size/3,dp1);  //not taking last index

    vector<vector<int>> dp2(size,vector<int>(size,-1));
    int case2=solveMem(1,size-1,slices,size/3,dp2);//not taking first index
    return max(case1,case2);
}

//Bottom Up approach
int maxSizeSlicesTab(vector<int> &slices){
    int k=slices.size();

    vector<vector<int>> dp1(k+2,vector<int>((k/3)+1,0));
    vector<vector<int>> dp2(k+2,vector<int>((k/3)+1,0));
    //k+2  because index+2
    for(int index=k-2;index>=0;index--){
        for(int n=1;n<=k/3;n++){
            int take=slices[index]+ dp1[index+2][n-1];
            int notTake = dp1[index+1][n];

            dp1[index][n]=max(take,notTake);
        }
    }
    int case1=dp1[0][k/3];

    for(int index=k-1;index>=1;index--){
        for(int n=1;n<=k/3;n++){
            int take=slices[index]+ dp2[index+2][n-1];
            int notTake = dp2[index+1][n];

            dp2[index][n]=max(take,notTake);
        }
    }
    int case2=dp2[1][k/3];

    return max(case1,case2);
}

//space optimization
int maxSizeSlicesSO(vector<int> &slices){
    int k=slices.size();

    vector<int> prev1(k+2,0);   //dp[index]
    vector<int> curr1(k+2,0);   //dp[index+1]
    vector<int> next1(k+2,0);   //dp[index+2]

    vector<int> prev2(k+2,0);
    vector<int> curr2(k+2,0);
    vector<int> next2(k+2,0);
    
    //k+2  because index+2
    for(int index=k-2;index>=0;index--){
        for(int n=1;n<=k/3;n++){
            int take=slices[index] + next1[n-1];
            int notTake = curr1[n];

            prev1[n]=max(take,notTake);
        }
        next1=curr1;
        curr1=prev1;
    }
    int case1=curr1[k/3];

    for(int index=k-1;index>=1;index--){
        for(int n=1;n<=k/3;n++){
            int take=slices[index]+ next2[n-1];
            int notTake = curr2[n];

            prev2[n]=max(take,notTake);
        }

        next2=curr2;
        curr2=prev2;
    }
    int case2=curr2[k/3];

    return max(case1,case2);
}

int main(){
    vector<int> slices = {1,2,3,4,5,6,7,8,9};
    cout<<maxSizeSlicesSO(slices);
}

