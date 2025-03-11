#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nearlySimilarRectangles' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts 2D_LONG_INTEGER_ARRAY sides as parameter.
 */
long long gcd(long long m,long long n){
    while(n!=0){
        long long temp=n;
        n=m%n;
        m=temp;
    }
    return m;
}

struct pair_hash{
    size_t operator()(const pair<long long,long long>&p) const{
        return hash<long long>()(p.first)^(hash<long long>()(p.second)<<1);
    }
};
long nearlySimilarRectangles(vector<vector<long>> sides) {
    long ans=0;
    unordered_map<pair<long long,long long>,long long,pair_hash> mpp;
    for(int i=0;i<sides.size();i++){
       long long w=sides[i][0];
       long long h=sides[i][1];
       long long g=gcd(w,h);
       pair<long long,long long> r={w/g,h/g};
       ans+=mpp[r];
       mpp[r]++;
    }
    return ans;
}

long nearlySimilarRectangles2(vector<vector<long>> sides) {
    long ans=0;
    unordered_map<double,long> mpp;
    for(int i=0;i<sides.size();i++){
       long long w=sides[i][0];
       long long h=sides[i][1];
       double k=(double)w/(double)h;
       mpp[k]++;
    }
    for(auto i:mpp){
        if(i.second>1){
            int n=i.second;
            ans+= n*(n-1)/2;
        }
    }
    return ans;
}

int main(){
    vector<vector<long>> sides={{4,8},{15,30},{25,50}};
    cout<<nearlySimilarRectangles2(sides);

}
