#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int lsum=0,rsum=0;
        for(int i=0;i<k;i++) lsum=lsum+card[i];
        int maxSum=lsum;
        int rIndex=n-1;
        for(int i=k-1;i>=0;i--){
            lsum= lsum-card[i];
            rsum=rsum+card[rIndex];
            rIndex--;

            maxSum=max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<int> card={1,2,3,4,5,6,1};
    int k=3;
    cout<<s.maxScore(card,k);
}