#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;
/*
string reverseString(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }

    return ans;
}

void deleteMiddleElement(stack<int> &s){  //iterative
    int k=0;
    int n=s.size()/2;
    stack<int> newStack;
    while(n!=0){
        newStack.push(s.top());
        s.pop();
        n--;
        k++;
    } 
    s.pop();    //delete the middle
    while(k!=0){
        s.push(newStack.top());
        newStack.pop();
        k--;
    }
}

void solveDeleteMiddle(stack<int> &s,int count,int size);
void deleteMiddleElement2(stack<int> &s){  //recursive
    int count=0;
    solveDeleteMiddle(s,count,s.size());
}

void solveDeleteMiddle(stack<int> &s,int count,int size){
    if(count==size/2){
        s.pop();
        return;
    }

    int num=s.top();
    s.pop();
    solveDeleteMiddle(s,count+1,size);
    s.push(num);
}
*/

template<class T>
void display(stack<T> s){
    stack<T> Mystack=s;  
    cout << "Stack elements: ";
    while (!Mystack.empty()) {
        cout << Mystack.top() << " ";  
        Mystack.pop();
    }
    cout << endl;
}
/*
bool ValidParenthesis(string str){
    stack<char> s;
    for(int i=0; i<str.length();i++){
        char ch=str[i];

        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if(( ch==')' && top=='(')|| (ch=='}' && top=='{' ) || ( ch==']' && top=='[' )){
                    s.pop();
                }
                else{  //condition false
                    return false;
                }
            }
            else{  //stack empty
                return false;
            }
        }
    }

    if(s.empty()){  //stack empty after for loop
        return true;
    }
    else{ //stack not empty after for loop
        return false;
    }
}

void pushAtBottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int temp=s.top();
    s.pop();

    pushAtBottom(s,x);
    s.push(temp);
}

void ReverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num=s.top();
    s.pop();
    ReverseStack(s);
    pushAtBottom(s,num);
}

*/

void insertSortively(stack<int> &s,int top){
    if(s.empty() ||(!s.empty() && s.top()<top)){
        s.push(top);
        return;
    }

    int n=s.top();
    s.pop();
    insertSortively(s,top);
    s.push(n);

}

void SortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num=s.top();
    s.pop(); 
    SortStack(s);
    insertSortively(s,num);
}

bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(' || ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            st.push(ch);
        }
        else{
            //ch ya toh ')' hai or lowercase letter

            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant=false;
                    }
                    st.pop();
                }

                if(isRedundant==true){
                    return true;
                }

                st.pop();
            }
        }
    }

    return false;
}


int findMinimumCost(string str){   // str example - {}}{}{{}{
    //odd condition - odd no. of brackets can't be solved
    if(str.length()%2==1){
        return -1;
    }

    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch= str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{
            //ch is } bracket
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    //stack has invalid expression now
    int a=0,b=0;
    while(!s.empty()){
        if(s.top()=='{'){
            a++;
        }
        else if(s.top()=='}'){
            b++;
        }
        s.pop();
    }
    
    int ans=(a+1)/2 + (b+1)/2;
    return ans;
}

vector<int> nextSmallerElement(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }

        //ans is stack ka top
        ans[i]=s.top();
        s.push(curr);
    }

    return ans;
}


vector<int> prevSmallerElement(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }

        //ans is stack ka top
        ans[i]=s.top();
        s.push(curr);
    }

    return ans;
}


int main(){
    //creatting stack
    stack<int> s;

    //pushing in stack
    s.push(10);
    s.push(12);
    s.push(18);
    s.push(2);
    s.push(38);
    //cout<<"Stack top element is: "<<s.top()<<endl;
    //pop in stack
    //s.pop();

    /*cout<<"Stack top element is: "<<s.top()<<endl;
    if(s.empty()){
        cout<<"Stack is empty\n";
    }
    else{
        cout<<"Stack is not empty\n";
    }*/

    
    //cout<<"Size of stack is:"<<s.size()<<endl;
    stack<int> Mystack=s;  //copy of stack
    //display(Mystack);


    string str1="Aman Jain";
    //string str2=reverseString(str1);
    //cout<<str2<<endl;

    //deleteMiddleElement2(s);
    
    //ReverseStack(s);
    //SortStack(s);
    //display(s);

    string bracstr;
    //cout<<"Enter the string: ";
    //cin>> bracstr;
    //cout<<findRedundantBrackets(bracstr);
    string k="}}}}}}";
    cout<<findMinimumCost(k);


}