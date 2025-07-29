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

        // insert digit
        // prevent leading 0, ...+0, 0...
        int n = expression.size();
        if (expression.empty() || expression.back() != '0' || n > 1 && isdigit(expression[n - 2])) {
            expression.push_back(num[index]);
            backtrack(index+1, expression, res, num, target);
            expression.pop_back();
        }

        // try all possible operator
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
        for (auto ch : s) {
            if (isdigit(ch)) {
                num = num*10 + (ch - '0');
                continue;
            }
            processOp(res, lastNum, num, lastOp);
            lastOp = ch;
            num = 0;
        }
        processOp(res, lastNum, num, lastOp);
        res += lastNum;
        return res;
    }

    void processOp(long& res, long& lastNum, long num, char lastOp) {
        if (lastOp == '+') {
            res += lastNum;
            lastNum = num;
            return;
        }
        if (lastOp == '-') {
            res += lastNum;
            lastNum = -num;
            return;
        }
        if (lastOp == '*') {
            lastNum *= num;
            return;
        }
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