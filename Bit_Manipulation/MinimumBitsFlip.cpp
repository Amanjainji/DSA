#include<bits/stdc++.h>
using namespace std;

int main(){
    int start=10;
    int end=7;
    int ans=start^end;
    int cnt=0;
    for(int i=0;i<=31;i++){
        if(ans& (1<<i)) 
            cnt++;
    }
    cout<<cnt;
}