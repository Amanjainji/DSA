#include<iostream>
using namespace std;

class heap{
    public:
     int arr[100];
     int size;

     heap(){
        arr[0]=-1;
        size=0;
     }

     void insert(int val){  //Max heap
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }                 
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletion(){  //T.C. -O(log n)
    //delete largest node
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        // step 1: put last element into first Index
        arr[1]=arr[size];
        //step 2: remove last element
        size--;

        //step 3: take root node to its correct position
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex= 2*i+1;
        if(leftIndex<size && arr[i]<arr[leftIndex]){
            swap(arr[i],arr[leftIndex]);
            i=leftIndex;
        }
        else if(rightIndex<size && arr[i]<arr[rightIndex]){
            swap(arr[i],arr[rightIndex]);
            i=rightIndex;
        }
        else{
            return;
        }
    }
  }

};

void heapifyMax(int arr[],int n,int i){  //heapify func - O(log n) but total heap- O(N)
    int largest= i;
    int left= 2*i;      //arr start from 1 index 
    int right= 2*i+1;        
    //if arr start from 0 index then left=2i+1 ,right= 2i+2

    if(left <= n && arr[largest]< arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest !=i){
        swap(arr[i],arr[largest]);
        heapifyMax(arr,n,largest);
    }
}

void heapifyMin(int arr[],int n,int i){   
/*The time complexity for building a heap using repeated heapify calls on all elements is indeed 
O(N), but each heapifyMin call has a complexity of 
O(logn).*/
    int smallest= i;
    int left= 2*i;   //let arr start from 1 index 
    int right= 2*i+1;        
    //if arr start from 0 index then left=2i+1 ,right= 2i+2

    if(left <= n && arr[smallest]> arr[left]){
        smallest=left;
    }
    if(right<=n && arr[smallest]>arr[right]){
        smallest=right;
    }

    if(smallest !=i){
        swap(arr[i],arr[smallest]);
        heapifyMin(arr,n,smallest);
    }
}


int main(){
    heap h1;
    h1.insert(10);
    h1.insert(30);
    h1.insert(50);
    h1.insert(40);
    h1.insert(20);

    //h1.deletion();
    //h1.print(

    int arr[6] = {-1,60,50,30,20,40};
    int arr1[6] = {-1,54,53,55,52,50};
    int n=5;  //nodes
    for(int i=n/2;i>0;i--){  //ignoring the leaf nodes as heap
        heapifyMax(arr,n,i);
    }
/*
    for(int i=n/2;i>0;i--){  //ignoring the leaf nodes as heap
        heapifyMin(arr1,n,i);
    }

    cout<<"Printing Heap Max array: "<<endl;
    for(int i=1;i<=n;i++){     // T.C. -O(n)
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
*/
    cout<<"Printing Heap Min array: "<<endl;
    for(int i=1;i<=n;i++){     // T.C. -O(n)
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
