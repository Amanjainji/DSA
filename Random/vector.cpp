#include <iostream>
#include <bits/stdc++.h> 
using namespace std;  

int main(){
    vector<int> v; 
    v.push_back(1);  //pusing in array
    v.push_back(3);
    v.push_back(2);


    //3 types of printing in a vector
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<int>:: iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;

    //pop back
    v.pop_back();
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;
    //same type of element in an vector
    vector<int> v2 (3,50); //50 50 50
    for(auto element:v2){
        cout<<element<<" ";
    }
    cout<<endl;
    //swap
    swap(v,v2);
    for(auto element:v2){
        cout<<element<<" ";
    }
    cout<<endl;

    //clearing a vector
    v.clear();
    v.push_back(100);
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;

    //erasing in array
    vector<int> myvector;
    for (int i=1; i<=10; i++){
        myvector.push_back(i);
    }
        // erase the 6th element
        myvector.erase (myvector.begin()+5);
        for(auto element:myvector){
        cout<<element<<" ";
        }
        cout<<endl;
        // erase the first 3 elements:
        myvector.erase (myvector.begin(),myvector.begin()+3);
        for(auto element:myvector){
            cout<<element<<" ";
        }
    cout<<endl;

    //assign in a vector
    vector<int> first;
    vector<int> second;
    vector<int> third;
    first.assign (7,100);             // 7 ints with a value of 100

    vector<int>::iterator it1;
    it1=first.begin()+1;
    second.assign (it1,first.end()-1); // the 5 central values of first

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.

    for(auto element:first){
            cout<<element<<" ";
        }
    cout<<endl;
    for(auto element:second){
            cout<<element<<" ";
        }
    cout<<endl;
    for(auto element:third){
            cout<<element<<" ";
        }
    cout<<endl;

    //inserting in an vector

    vector<int> vector1 (3,100);
    vector<int>::iterator it2;
    it2 = vector1.begin()+2;
    vector1.insert(it2,1,50);
    for(auto element:vector1){
            cout<<element<<" ";
        }
    cout<<endl;
    //sorting 
    sort(myvector.begin(),myvector.end());
     for(auto element:myvector){
            cout<<element<<" ";
        }
    cout<<endl;




    return 0;}


