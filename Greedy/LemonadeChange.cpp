#include<bits/stdc++.h>
using namespace std;

/*
The problem is the Lemonade Change problem (LeetCode 860):

You sell lemonade for $5.

Customers come one by one and pay with either a $5, $10, or $20 bill.

You must give back the correct change if needed.

Initially, you have no money in hand.

You need to return true if you can give change to every customer, otherwise false.
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) five++;
            else if (bills[i] == 10) {
                if (five) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                if (ten && five) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){

}
