#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(0, 0, "", n, res);
        return res;        
    }

private:
    void solve(int openP, int closeP, string s, int n, vector<string>& res) {
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s);
            return;
        }

        if (openP < n) {
            solve(openP + 1, closeP, s + "(", n, res);
        }

        if (closeP < openP) {
            solve(openP, closeP + 1, s + ")", n, res);
        }
    }
};

int main(){
    Solution s;
    vector<string> k=s.generateParenthesis(3);
    for(auto i:k){
        cout<<i<<"    ";
    }
}