#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    map<int,int> mp;

    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int curr = 0;
        for (auto &i : mp) {
            int t=i.first;  //time
            int v=i.second; //val
            curr += v;
            if (curr > 2) {
                mp[start]--;    //backtrack
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

int main(){
    MyCalendarTwo* obj=new MyCalendarTwo();
    cout<<obj->book(10,20)<<" ";
    cout<<obj->book(10,40)<<" ";
    cout<<obj->book(5,15)<<" ";
}