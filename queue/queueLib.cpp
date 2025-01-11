#include<iostream>
#include<queue>
using namespace std;

int main(){
    //create a queue
    queue<int> q;
    q.push(10);
    q.push(15);
    q.push(13);

    cout<<"size of queue is:"<<q.size()<<endl;

    q.pop();
    cout<<"size of queue is:"<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else    
        cout<<"Queue is not empty"<<endl;


    cout<<"front of queue is : "<<q.front()<<endl;
    cout<<"rear of queue is : "<<q.back()<<endl;

}