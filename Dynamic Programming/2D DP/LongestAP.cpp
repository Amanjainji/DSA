#include<bits/stdc++.h>
using namespace std;
/*
Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

Examples:

Input:arr[] = [1, 7, 10, 13, 14, 19]
Output: 4
Explanation: The longest arithmetic progression is [1, 7, 13, 19].
*/

//Recursion
int solve(int index,int diff, int A[]){
    //backward check
    if(index<0)
        return 0;
    
    //Agr uss index pr already uss diffrence ka element padha wa hai
    int ans=0;
    for(int j=index-1;j>=0;j--){
        if(A[index]-A[j]==diff){
            ans=max(ans,1+solve(j,diff,A));
        }
    }

    return ans;
}

int lengthOfLongestAP(int A[],int n){
    if(n<=2)
        return n;
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,2+solve(i,A[j]-A[i],A));
        }
    }
    return ans;
}

//Recursion + memoization
int solveMem(int index,int diff, int A[],unordered_map<int,int> dp[]){
    //backward check
    if(index<0)
        return 0;
    
    //Agr uss index pr already uss diffrence ka element padha wa hai
    if(dp[index].count(diff)){
        return dp[index][diff];
    }

    int ans=0;
    for(int j=index-1;j>=0;j--){
        if(A[index]-A[j]==diff){
            ans=max(ans,1+solveMem(j,diff,A,dp));
        }
    }

    return dp[index][diff]=ans;
}

int lengthOfLongestAPMem(int A[],int n){
    if(n<=2)
        return n;
    int ans=0;

    unordered_map<int,int> dp[n+1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,2+solveMem(i,A[j]-A[i],A,dp));
        }
    }
    return ans;
}

//Tabulation
int lengthOfLongestAPTab(int A[],int n){
    if(n<=2)
        return n;
    int ans=0;

    unordered_map<int,int> dp[n+1];
    for(int i=1;i<n;i++){  //for all elements
        for(int j=0;j<i;j++){      //for all diffrences
            int diff=A[i]-A[j];
            int cnt=1;
            if(dp[j].count(diff)){
                cnt= dp[j][diff];
            }

            dp[i][diff]=1+cnt;
            ans=max(ans,dp[i][diff]);
        }
    }
    return ans;
}
    
int main(){
    int arr[6] = {1, 7, 10, 13, 14, 19};
    cout<<lengthOfLongestAPTab(arr,6);
}