#include<bits/stdc++.h>
using namespace std;

class Solution {
    /*
Explanation:

mini = minimum number of open ( needed.

maxi = maximum number of open ( possible.

When mini < 0 → dont decrease more.

If maxi < 0 at any point → invalid.

At the end, mini == 0 means all parentheses can be matched
    */
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;  
        for (char c : s) {
            if (c == '(') {
                mini++; 
                maxi++;
            } else if (c == ')') {
                if (mini > 0) mini--;  
                maxi--;  
            } else { // '*'
                if (mini > 0) mini--;  
                maxi++;  
            }
            if (maxi < 0) return false; 
        }
        return mini == 0;
    }
};

/*
The algorithm ensures that we never close more parentheses than opened (via maxi < 0 check) and never let mini drop below 0.

So it's a greedy bounding strategy — making the locally optimal choice of updating the min/max range at each character, which guarantees correctness.
*/

int main(){

}