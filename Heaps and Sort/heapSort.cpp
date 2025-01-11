#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){  //heapify func - O(log n) 
    int largest= i;
    int left= 2*i;      //heap_arr start from 1 indexing 
    int right= 2*i+1;        
    //if heap_arr start from 0 indexing then left=2i+1 ,right= 2i+2

    if(left <= n && arr[largest]< arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest !=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2;i>0;i--){  //ignoring the leaf nodes as heap
        heapify(arr,n,i);
    }
    while(n>1){
        //step 1 - swap with largest element
        swap(arr[n],arr[1]);
        n--;

        //step 2 - make max heap CBT again
        heapify(arr,n,1);
    }
}

int main(){

    int arr[6] = {-1,54,53,55,52,50};
    int n=5;  //nodes
    heapSort(arr,n);
  
    cout<<"Printing Heap Sorted array: "<<endl;
    for(int i=1;i<=n;i++){     
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    
    return 0;
}
