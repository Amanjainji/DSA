#include<bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> mpp;  // ball -> color
    unordered_map<int, int> colorCount;  // color -> count of balls using this color
    vector<int> ans;
    int temp = 0;

    for (auto& i : queries) {
        int ball = i[0], newColor = i[1];

        if (mpp.find(ball) == mpp.end()) {  // Ball doesn't exist
            mpp[ball] = newColor;
            if (colorCount[newColor] == 0) {  // New color introduced
                temp++;
            }
            colorCount[newColor]++;
            ans.push_back(temp);
        } 
        else if (mpp[ball] == newColor) {  // Ball already has this color
            ans.push_back(temp);
        } 
        else {  // Ball exists but has a different color
            int oldColor = mpp[ball];

            // Remove old color if it was the last one
            if (--colorCount[oldColor] == 0) {
                temp--;
            }

            // Assign new color
            mpp[ball] = newColor;
            if (colorCount[newColor] == 0) {
                temp++;
            }
            colorCount[newColor]++;

            ans.push_back(temp);
        }
    }
    return ans;
}