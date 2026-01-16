#include<bits/stdc++.h>
using namespace std;

bool foundOdd(int n){
    while(n>0){
        int digit=n%10;
        if(digit%2==1){
            return true;
        }
        n/=10;
    }
    return false;
}

vector<int> getDigits(int n){
    vector<int> digits(10,0);
    while(n>0){
        int digit=n%10;
        digits[digit]++;
        n/=10;
    }
    vector<int> v;
    for(int i=1;i<10;i++){
        if(digits[i]>0)
            v.push_back(i);
    }
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==1){
            cout<<0<<endl;
            continue;
        }
        if(foundOdd(n)){
            cout<<1<<endl;
            continue;
        }
        queue<pair<int,int>> q;
        q.push({n,0});
        unordered_set<int> visited;
        visited.insert(n);
        bool found=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int num=curr.first;
            int dist=curr.second;

            vector<int> digits=getDigits(num);
            for(auto i: digits){
                int next=num-i;
                if(next<0 || visited.count(next))
                    continue;
                if(next%2){
                    cout<<dist+1<<endl;
                    found=1;
                    break;
                }
                if(!found && foundOdd(next)){
                    cout<<dist+2<<endl;
                    found=1;
                    break;
                }
                visited.insert(next);
                q.push({next,dist+1});
            }
            if(found){
                break;
            }
        }
        if(!found)
            cout<<-1<<endl;
    }
}


// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string s;
//         cin>>s;
//         vector<int> freq(26,0);
//         bool flag=true;
//         for(auto i: s){
//             freq[i-'a']++;
//             if(freq[i-'a']>2){
//                 flag=0;
//                 break;
//             }
//         }
//         if(flag)
//             cout<<"YES"<<endl;
//         else
//             cout<<"NO"<<endl;

//     }
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//     int n,a,b;
//     cin>>n>>a>>b;
//     vector<int> temp(n);
//     for(int i=0;i<n;i++)
//         cin>>temp[i];
//     bool jacket=false;
//     int ans=0;
//     for(int i=0;i<n;i++){
//         if(!jacket && temp[i]>=a){
//             continue;
//         }
//         else if(jacket && temp[i]<=b){
//             continue;
//         }
//         else{
//             if(!jacket)
//                 ans++;
//             jacket=!jacket;
//         }
//     }
//     cout<<ans<<endl;
    
    
//     }
    
// }