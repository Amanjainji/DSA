/*
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.

 

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    void backtrack(int index, string& expression, vector<string>& res, const string& num, int target) {
        if (index >= num.size()) {
            if (eval(expression) == target) {
                res.push_back(expression);
            }
            return;
        }

        // Inserting Digits (without operator)
        // prevent leading 0, ...+0, 0...
        /*
        Tries to add current digit directly to the expression (to form multi-digit numbers like 23, 123).
        Prevents leading zeros (like "01" is not valid)
        isdigit(expression[n - 2]): To check if the character before the '0' is a digit (i.e., we’re currently building a number, like "10", "230", etc.)
        */
        int n = expression.size();
        if (expression.empty() || expression.back() != '0' || n > 1 && isdigit(expression[n - 2])) {
            expression.push_back(num[index]);
            backtrack(index+1, expression, res, num, target);
            expression.pop_back();
        }

        // try all possible operator
        /*
        Only inserts operator if the last character in expression is a digit
        Tries all 3 operators before current digit
        After inserting operator, calls backtrack again (same index because digit still needs to be inserted)
        */
        for (auto op: {'+', '-', '*'}) {
            if (expression.empty() || !isdigit(expression.back())) {
                continue;
            }

            expression.push_back(op);
            backtrack(index, expression, res, num, target);
            expression.pop_back();
        }
    }
long eval(const string& s) {
    long num = 0, lastNum = 0, res = 0;
    char lastOp = '+';
    /*
    lastNum to store the previous value (affected by *)
    lastOp to remember which operation to apply next
    */
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        if (!isdigit(ch) || i == s.size() - 1) {
            if (lastOp == '+') {
                /*
                Why? Because in res += lastNum, you're delaying addition until after multiplication is resolved (like how 2+3*4 becomes 2+(3*4)).
                */
                res += lastNum;
                lastNum = num;
            } else if (lastOp == '-') {
                res += lastNum;
                lastNum = -num;
            } else if (lastOp == '*') {
                lastNum *= num;
                /*
                Important part: if the last operation was *, then we multiply lastNum by the current number and don't touch res yet.This handles the precedence of * over + and -. You delay adding lastNum to res until you're done multiplying.
                */
            }
            /*
            Save the current operator for use in the next iteration
            Reset num to start building the next number
            */
            lastOp = ch;
            //You finally add the last computed value (which may already include multiplication) to res
            num = 0;
        }
    }

    res += lastNum;
    return res;
}

public:
    // Time: O(n*2^n)
    // Space: O(n)
    vector<string> addOperators(string num, int target) {
        // use backtracking try all possible positions to insert operator
        string expression;
        int index = 0;
        vector<string> res;
        backtrack(index, expression, res, num, target);
        return res;
    }
};

int main(){
    Solution s;
    vector<string> k=s.addOperators("123",6);
    for(auto i:k){
        cout<<i<<"    ";
    }
}