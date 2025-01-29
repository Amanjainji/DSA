#include<bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    if (changed.size() % 2 != 0)
        return {};

    unordered_map<int, int> freq;
    for (int num : changed)
        freq[num]++;

    vector<int> result;
    sort(changed.begin(), changed.end());

    for (int num : changed) {
        if (freq[num] == 0)  // Already used in a pair
            continue;

        if (freq[num * 2] == 0)  // No pair exists
            return {};

        result.push_back(num);
        freq[num]--;
        freq[num * 2]--;
    }

    return result;
}

int main(){
    vector<int> changed = {1,3,4,2,6,8};
    //vector<int> changed = {1};
    //vector<int> changed = {4,4,16,20,8,8,2,10};
    vector<int> k=findOriginalArray(changed);
    for(auto i:k){
        cout<<i<<" "; 
    }
}