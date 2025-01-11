#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;

void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

//1 Reversing a Queue
void queueReverse(queue<int> &q){
    if(q.empty()){
        return;
    }
    int num=q.front();
    q.pop();
    queueReverse(q);
    q.push(num);
}


//2 print first Negative integer in k side window
vector<int> printfirsttNegativeInteger(int A[],  int N ,int k){
    deque<int> dq;
    vector<int> ans;

    //process first window of k size
    for(int i=0;i<k;i++){
        if(A[i]<0){
            dq.push_back(i);  //pushing index
        }
    }

    //store answer of first k size window
    if(dq.size() >0)
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);
    
    //process for remaining windows
    for(int i=k;i<N;i++){
        //removal
        if(!dq.empty() && i- dq.front()>=k){
            dq.pop_front();
        }

        //addition
        if(A[i]<0)
            dq.push_back(i);

        //ans store
        if(dq.size() >0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

//3 Reverse only first k elements of queue
queue<int> modifyQueue(queue<int> que,int k){
    queue<int> q=que;
    stack<int> s;
    //push k element in stack
    for(int i=0;i<k;i++){   
        int num=q.front();
        q.pop();
        s.push(num);
    }

    //push back in queue in reverse order
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    //maintain the remaing order
    int n=q.size();
    for(int i=0;i<n-k;i++){
        int num1=q.front();
        q.pop();
        q.push(num1);
    }

    return q;
}

//4 Reverse K element in queue
queue<int> ReverseK(queue<int> que,int k){
    queue<int> q=que;
    stack<int> s;

    int n=q.size();
    int count=n/k;
    int remaining=n%k;
    int start=0,end=k;
    while(count>0){  
        for(int i=start;i<end;i++){ 
                int num=q.front();
                q.pop();
                s.push(num);
            }

        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        count--;
        start+=k;
        end+=k;
    }

    //fixing the remaing elements
    for(int i=0;i<remaining;i++){
        int num1=q.front();
        q.pop();
        q.push(num1);
    }

    return q;
}

//5 first Non repeating character in a string
string FirstNonRepeating(string A){
    unordered_map<char,int> count;
    queue<int> q;
    string ans;

    for(int i=0;i<A.length();i++){
        char ch=A[i];

        //increase count
        count[ch]++;

        //queue mein push karo
        q.push(ch);


        while(!q.empty()){
            if(count[q.front()]>1){  //repeating character
                q.pop();
            }
            else{
                //non repeating character
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty())
           ans.push_back('#'); 
        
    }
    return ans;
}

//6 interleave two halves of a queue

// 6(i)using Queue
void interleaveQueue(queue<int> &q){
    int n=q.size()/2;
    queue<int> q2;
    while(n>0){
        int num=q.front();
        q.pop();
        q2.push(num);
        n--;
    }

    bool flag=false;
    if(q2.size()<q.size())  //for odd elements case
        flag=true;

    while(!q2.empty()){
        int n1=q2.front();
        q2.pop();
        q.push(n1);

        int n2=q.front();
        q.pop();
        q.push(n2);
    }

    if(flag){
        q.push(q.front());
        q.pop();
    }
}

//6 (ii) using stack
//just implement queue using stack and same as above
void interleaveQueueusingStack(queue<int> &q){
    int n=q.size()/2;
    stack<int> s;

    while(n>0){  //fill stack with first half
        int num=q.front();
        q.pop();
        s.push(num);
        n--;
    }
    
    while(!s.empty()){   // push back in queue from stack
        int n1=s.top();
        s.pop();
        q.push(n1);
    }

    n=q.size()/2;
    while(n>0){   //now push second half in queue from front
        q.push(q.front());
        q.pop();
        n--;
    }

    n=q.size()/2;
    while(n>0){  //now again fill the queue with first half
        int num=q.front();
        q.pop();
        s.push(num);
        n--;
    }

  
    while(!s.empty()){  //interleave now using stack
        int n1=s.top();
        s.pop();
        q.push(n1);

        int n2=q.front();
        q.pop();
        q.push(n2);
    }

}


//7 Sum of max term and min term in a k size window of an array

int solvemaxmin(int *arr,int n,int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    //addition of first k size window
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()]>=arr[i])
            mini.pop_back();

        maxi.push_back(i);    //addition of index
        mini.push_back(i);   //addition of index
    }

    int ans=0;
    ans+= arr[maxi.front()]+arr[mini.front()];
    for(int i=k;i<n;i++){
        //next window

        //removal
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }

        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()]>=arr[i])
            mini.pop_back();

        maxi.push_back(i);    //addition of index
        mini.push_back(i);   //addition of index

        ans+= arr[maxi.front()]+arr[mini.front()];
    }    

    return ans;
}



int main(){
    //create a queue
    queue<int> q;
    q.push(10);
    q.push(15);
    q.push(13);
    q.push(23);
    q.push(3);
    q.push(6);
    //cout<<q.front();
    //queueReverse(q);
    //display(q);

    /*
    int A[]={-8,6,-2,-3,5,9};
    vector<int> ans=printfirsttNegativeInteger(A,6,2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    */
 
    //queue<int> m=modifyQueue(q,3);
    //display(m);

    queue<int> mo=ReverseK(q,2);
    //display(mo);
    
    string str="aabc";
    //string s=FirstNonRepeating(str);
    //cout<<s<<endl;

    queue<int> que;
    que.push(11);
    que.push(12);
    que.push(13);
    que.push(14);
    que.push(15);
    que.push(16);
    que.push(17);
    que.push(18);
    interleaveQueue(que);
    //interleaveQueueusingStack(que);
    //display(que);

    int arr1[7]={2,5,-1,7,-3,-1,-2};
    cout<<solvemaxmin(arr1,7,4);


}