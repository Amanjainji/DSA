#include<bits/stdc++.h>
using namespace std;

/*
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000

Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack.
*/ 


//Soln-  jiski per unit value sabse jyada , woho knapsack mein daalo
struct Item{
    int value;
    int weight;
};

static bool cmp(pair<double,Item> a,pair<double,Item> b){
    return a.first> b.first;     //decreasing order
} 
//W - capacity
double fractionalKnapsack(int W,Item arr[],int n){
    vector<pair<double,Item>> v;
    for(int i=0;i<n;i++){
        Item item=arr[i];
        double perUnitValue=(1.0*item.value)/item.weight;
        v.push_back(make_pair(perUnitValue,item));
    }

    sort(v.begin(),v.end(),cmp);

    double totalValue=0.0;
    for(int i=0;i<n;i++){
        if(v[i].second.weight>W){
            //toh sirf fractional part hi le paunga
            totalValue+=v[i].first * W;
            W=0;
            break;
        }
        else{
            //pura le skta hu
            totalValue+=v[i].second.value;
            W-=v[i].second.weight;
        }
    }

    return totalValue;
}

int main(){
    Item item[]={{60,10},{100,20},{120,30}};
    int capacity = 50;
    printf("%f",fractionalKnapsack(capacity,item,3));
}