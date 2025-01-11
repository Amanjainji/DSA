#include<iostream>
#include<queue>
using namespace std;

int main(){
    //max heap
    cout<<"Max Heap"<<endl;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);

    cout<<"Element at top:"<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top:"<<pq.top()<<endl;
    cout<<"Size is "<< pq.size() <<endl;
    if(pq.empty()){
        cout<< "PQ is empty"<<endl;
    }
    else{
        cout<< "PQ is not empty"<<endl;
    }

    cout<<endl<<endl;

    //min heap
    cout<<"Min Heap"<<endl;
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(40);
    pq1.push(20);
    pq1.push(10);
    pq1.push(30);

    cout<<"Element at top:"<<pq1.top()<<endl;
    pq1.pop();
    cout<<"Element at top:"<<pq1.top()<<endl;
    cout<<"Size is "<< pq1.size() <<endl;
    if(pq1.empty()){
        cout<< "PQ is empty"<<endl;
    }
    else{
        cout<< "PQ is not empty"<<endl;
    }

}