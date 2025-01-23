#include<bits/stdc++.h>
using namespace std;
/*
Problem statement
You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.

Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.

But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.Input is given such that the answer will fit in a 32-bit integer. 

For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9.
*/

//recursive
int solve(vector<int> &num,int tar){
    if(tar<0)
        return 0;
    if(tar==0)
        return 1;
    
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solve(num,tar-num[i]);
    }
    return ans;  
}
int findWays(vector<int> &num,int tar){
    return solve(num,tar);
}

//recursive + memoization
int solve2(vector<int> &num,int tar,vector<int> &dp){
    if(tar<0)
        return 0;
    if(tar==0)
        return 1;
    if(dp[tar]!=-1)
        return dp[tar];
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solve2(num,tar-num[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];

}
int findWays2(vector<int> &num,int tar){
    vector<int> dp(tar+1,-1);
    return solve2(num,tar,dp);
}

//tabulation
int findWays3(vector<int> &num,int tar){
    vector<int> dp(tar+1,0);  //must be initialized with 0 else give negative answers
    dp[0]=1;
    for(int i=1;i<=tar;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0)
                dp[i]+=dp[i-num[j]];
        }
    }
    return dp[tar];
}

//Combination sum I
/*
void func(vector<int> &num, int tar, vector<vector<int>> &ans, vector<int> &temp, int start) {
    if (tar < 0)
        return; 
    if (tar == 0) {
        ans.push_back(temp); 
        return;
    }
    for (int i = start; i < num.size(); i++) {
        temp.push_back(num[i]); // Choose the current number
        func(num, tar - num[i], ans, temp, i); // Recur with updated target
        temp.pop_back(); // Backtrack to explore other possibilities
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    func(candidates, target, ans, temp, 0);
    return ans;
}
*/

void func2(vector<int> &num, int tar, vector<vector<int>> &ans, vector<int> &temp, int start) {
    if (tar == 0) {
        ans.push_back(temp); 
        return;
    }
    for (int i = start; i < num.size(); i++) {
        // Skip duplicate elements to avoid duplicate combinations
        if (i > start && num[i] == num[i - 1]) 
            continue;
        if (num[i] > tar) 
            break; // No need to proceed further as the array is sorted
        temp.push_back(num[i]); // Choose the current number
        func2(num, tar - num[i], ans, temp, i + 1); // Recur with updated target
        temp.pop_back(); // Backtrack to explore other possibilities
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and optimize
    func2(candidates, target, ans, temp, 0);
    return ans; 
}

void func3(vector<int> &num, int tar,int k, vector<vector<int>> &ans, vector<int> &temp, int start) {
    if (tar == 0 && temp.size()==k) {
        ans.push_back(temp); 
        return;
    }
    for (int i = start; i < num.size(); i++) {
        // Skip duplicate elements to avoid duplicate combinations
        if (i > start && num[i] == num[i - 1]) 
            continue;
        if (num[i] > tar) 
            break; // No need to proceed further as the array is sorted
        temp.push_back(num[i]); // Choose the current number
        func3(num, tar - num[i],k, ans, temp, i + 1); // Recur with updated target
        temp.pop_back(); // Backtrack to explore other possibilities
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> nums;
    for(int i=1;i<=9;i++){
        nums.push_back(i);
    }
    func3(nums, n,k, ans, temp, 0);
    return ans; 
}
int main(){
    /*
    vector<int> num={2,3,6,7};
    cout<<findWays3(num,5)<<endl;
    vector<vector<int>> k=combinationSum(num,7);
    
    vector<int> candidates = {10,1,2,7,6,1,5};int target = 8;
    vector<vector<int>> k=combinationSum2(candidates,target);
    for(auto i:k){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    vector<vector<int>> k=combinationSum3(4,1);
    for(auto i:k){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}