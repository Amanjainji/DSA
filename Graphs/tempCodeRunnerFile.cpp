#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long total=n*(n+1)/2;
        int centre=-1;
        for(int i=1;i<=n;i++){
            long long square=i*(total-i);
            int root=sqrt(square);
            if(root*root==square){
                centre=i;
                break;
            }
        }

        if(centre==-1) cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++){
                if(i==centre) continue;
                else{
                    cout<<centre<<" "<<i<<endl;
                }
            }
        }
    }
}