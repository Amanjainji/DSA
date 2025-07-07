#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int i, int j){
    
    // base condition
    if(i == j)
        return 0;
        
    int mini = INT_MAX;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k) + f(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    int i =1;
    int j = N-1;
    
    
    return f(arr,i,j);   
}

//vector<vector<int>> dp(N,vector<int>(N,-1));

int f2(vector<int>& arr, int i, int j,vector<vector<int>> &dp){
    
    // base condition
    if(i == j)
        return 0;
        
    int mini = INT_MAX;
    if(dp[i][j]!=-1)
        return dp[i][j];
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f2(arr,i,k,dp) + f2(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return dp[i][j]=mini;
}


int matrixMultiplication2(vector<int>& arr, int N){
    
    int i =1;
    int j = N-1;
    vector<vector<int>> dp(N,vector<int>(N,-1));
    
    return f2(arr,i,j,dp);
    
    
}
int main() {
	
	vector<int> arr = {4,5,3,2};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication2(arr,n);
	
	return 0;
}