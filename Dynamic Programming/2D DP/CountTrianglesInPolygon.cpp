#include<bits/stdc++.h>
using namespace std;

/*
The Catalan numbers are a sequence of natural numbers that occur in various counting problems, often involving recursively defined objects. They are named after Eugène Catalan, though they were previously discovered in the 1730s by Minggatu.

The n-th Catalan number can be expressed directly in terms of the central binomial coefficients by:
Cn = (2n)! / (n+1)! n! 

The first Catalan numbers for n = 0, 1, 2, 3, ... are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, etc.. 

*/

long long int factorial(int n,vector<long long int> &dp){
    if(dp[n]!=-1)
        return dp[n];

    dp[n]= n*factorial(n-1,dp);
    return dp[n];
}

//Catalan number
int CountTriangulation(int n){
    vector<long long int> dp(2*n+1,-1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    n=n-2;
    int count=factorial(2*n,dp)/(factorial(n+1,dp)*factorial(n,dp));
    return count;
}

int main(){
    cout<<CountTriangulation(7);
}