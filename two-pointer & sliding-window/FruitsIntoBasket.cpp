#include<bits/stdc++.h>
using namespace std;

/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick. 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
*/

//brute force TC - O(N^2)
int totalFruit(vector<int>& fruits) {
    int n=fruits.size();
    int maxlen=0;
    int k=2;
    for(int i=0;i<n;i++){
        unordered_set<int> st;
        for(int j=i;j<n;j++){
            st.insert(fruits[j]);
            if(st.size()<=k)
                maxlen=max(maxlen,j-i+1);
            else
                break;
        }
    }
    return maxlen;
}

//two pointer - TC - O(2N)
int totalFruit1(vector<int>& fruits) {
    int l=0,r=0,maxlen=0;
    unordered_map<int,int> mpp;
    int n=fruits.size();
    while(r<n){
        mpp[fruits[r]]++;
        while(mpp.size()>2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);
            l++;
        }
        if(mpp.size()<=2)
            maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

//sliding window TC - O(N)
int totalFruit2(vector<int>& fruits) {
    int l=0,r=0,maxlen=0;
    unordered_map<int,int> mpp;
    int n=fruits.size();
    while(r<n){
        mpp[fruits[r]]++;
        if(mpp.size()>2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);
            l++;
        }
        if(mpp.size()<=2)
            maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> fruits={1,2,1,3,3,1,4,1};
    cout<<totalFruit(fruits);
}