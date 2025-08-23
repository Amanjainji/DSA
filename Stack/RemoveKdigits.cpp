#include<bits/stdc++.h>
using namespace std;

/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;  
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        // Remove remaining k digits from the end of the stack
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        // Construct the resulting string from the stack
        string result="";
        while (!stack.empty()) {
            result= stack.top()+result;
            stack.pop();
        }
        
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == string::npos) ? "0" : result.substr(pos);
        return result;
    }
};

int main(){
    string num = "1432219";
    int k = 3;
    Solution s;
    cout<<s.removeKdigits(num,k);
}