#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string s;
//         cin>>s;
//         vector<int> ones;
//         for(int i=0;i<n;i++){
//             if(s[i]=='1') ones.push_back(i);
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='1') continue;
//             auto it=upper_bound(ones.begin(),ones.end(),i);
//             int idx;
//             if(it==ones.begin())
//                 idx=ones.back();
//             else{
//                 it--;
//                 idx=*it;
//             }

//             int d= (i-idx+n)%n;
//             ans=max(ans,d);
//         }
//         cout<<ans<<endl;  
//     }
// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> A(n);
//         for(int i=0;i<n;i++)
//             cin>>A[i];
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(A[i]==-1) continue;
//             for(int j=i+1;j<n;j++){
//                 if(A[j]<A[i] && A[j]!=-1){
//                     ans++;
//                     A[j]=-1;
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     }
// }
