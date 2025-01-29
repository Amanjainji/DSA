#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    // Roman numeral values and their corresponding symbols
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string ans = "";
    for (const auto &pair : roman) {
        while (num >= pair.first) {
            ans += pair.second;
            num -= pair.first;
        }
    }
    return ans;
}

int main(){
    cout<<intToRoman(1994);
}