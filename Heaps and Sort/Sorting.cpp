#include <iostream>
using namespace std;

//Bubble sort
void Bubble(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int flag=0;
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp;
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        flag=1;
      }
    }
    if(flag==0){
      break;
    }
  }
}
//Insertion Sort
void insertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
//Selection sort
void selectionSort(int *arr,int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(arr[i],arr[min_index]);
        }
    }
}

//Quick sort
int pivot(int *arr,int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}

void QuickSort(int *arr,int lb,int ub){
    if(lb<ub){
        int pivot_loc=pivot(arr,lb,ub);
        QuickSort(arr,lb,pivot_loc-1);
        QuickSort(arr,pivot_loc+1,ub);
    }
}

void merge(int *arr,int low ,int mid,int high){
    //size of two array
    int n1=mid-low+1;
    int n2=high-mid;

    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j]){
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++; 
        k++;
    }
}

void mergeSort(int *arr,int low,int high){
    if(low<high){
        int mid=(high+low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[5]={57,84,26,31,11};
    //QuickSort(arr,0,4);
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;




}