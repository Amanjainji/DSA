#include<bits/stdc++.h>
using namespace std;

/*
There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.

*/

int minimumDays(int S, int N, int M) {
    if(M>N)
        return -1;
    
    int buyingDays = S - (S/7);    //Sundays = S/7

    int ans=0;
    
    if((S*M)%N==0)
        ans= (S*M)/N;
    
    if((S*M)%N>0)
        ans=((S*M)/N) + 1;

    if(ans<=buyingDays)
        return ans;
    else
        return -1;   
}

int main(){
    cout<<minimumDays(10,1,1);
}