#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //creation of hash table
    unordered_map<string,int> m;

    //insertion
    //1
    pair<string,int> p=make_pair("babbar",3);
    m.insert(p);

    //2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //3
    m["mera"]=1;

    //updation
    m["mera"]=4;

    //searching 
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    //cout<<m.at("unknown")<<endl;  //error

    cout<<m["unknown"]<<endl;   //it will give 0
    cout<<m.at("unknown")<<endl;  //now it will not give error , will give 0

    //size
    cout<<"Size of this map is: "<<m.size()<<endl;

    //to check presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("love")<<endl;

    //erase
    m.erase("love");
    cout<<"New size after erase: "<<m.size()<<endl;

    //iteration
    //1
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl<<endl;
    //2
    unordered_map<string,int> :: iterator it =m.begin();
    while(it!=m.end()){
        cout<<it->first <<" "<<it->second<<endl;
        it++;
    }

    return 0; 

}