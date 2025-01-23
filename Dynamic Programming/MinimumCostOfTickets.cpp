#include<bits/stdc++.h>
using namespace std;
/*
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. 
For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
*/

//Recursive
/*
int solve(int n,vector<int> &days,vector<int> &cost,int index){
    //base case
    if(index>=n)
        return 0;

    //1 Day pass
    int option1=cost[0]+solve(n,days,cost,index+1);

    //7 day pass
    int i;
    //to get index after 7 days or end of days
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int option2=cost[1]+solve(n,days,cost,i);

    //30 day pass
    //to get index after 7 days or end of days
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int minimumCoins(int n,vector<int> days,vector<int> cost){
    return solve(n,days,cost,0);
}
*/
//Recursive + memoization
int solveMem(int n,vector<int> &days,vector<int> &cost,int index,vector<int> &dp){
    //base case
    if(index>=n)
        return 0;

    if(dp[index]!=-1)
        return dp[index];

    //1 Day pass
    int option1=cost[0]+solveMem(n,days,cost,index+1,dp);

    //7 day pass
    int i;
    //to get index after 7 days or end of days
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int option2=cost[1]+solveMem(n,days,cost,i,dp);

    //30 day pass
    //to get index after 7 days or end of days
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solveMem(n,days,cost,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];
}

int minimumCoinsMem(int n,vector<int> days,vector<int> cost){
    vector<int> dp(n+1,-1);
    return solveMem(n,days,cost,0,dp);
}

//Tabulation - Bottom Up
int minimumCoinsTab(int n,vector<int> days,vector<int> cost){
    vector<int> dp(n+1,INT_MAX);
    //base case
    dp[n]=0;
    for(int k=n-1;k>=0;k--){
        //1 Day pass
        int option1=cost[0]+dp[k+1];

        //7 day pass
        int i;
        //to get index after 7 days or end of days
        for(i=k;i<n && days[i]<days[k]+7;i++);

        int option2=cost[1]+dp[i];

        //30 day pass
        //to get index after 7 days or end of days
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int option3=cost[2]+dp[i];

        dp[k]=min(option1,min(option2,option3));
    }
    return dp[0];
}

//Space optimzed - O(1)
//O(1) EVEN AFTER QUEUE because queue have max 30 elemnts or 7 elements

int minimumCoinsSO(int n,vector<int> days,vector<int> cost){
    int ans=0;
    queue<pair<int,int>> month; // <current_day,cost>
    queue<pair<int,int>> week;

    for(int day:days){
        //step 1: remove expired days
        while(!month.empty() && month.front().first+30 <=day)
            month.pop();
        

        while(!week.empty() && week.front().first+7 <=day)
            week.pop();

        //step 2: current day ka pair banakr daal do queue mein
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        //step 3: ans update
        ans=min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;
}
int main(){
    vector<int> days={2,3,4,7,8,9,20};
    int n=days.size();
    vector<int> cost={2,5,20};
    cout<<"Cost: "<<minimumCoinsSO(n,days,cost);
}