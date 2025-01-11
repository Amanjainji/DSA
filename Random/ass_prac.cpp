#include <iostream>
using namespace std;

int Linear_search(int *arr,int n,int key){
    if(n==0)
        return -1;
    if(arr[n-1]==key){
        return n-1;
    }
    else{
        return Linear_search(arr,n-1,key);
    }
}

int max_min_array(int *arr,int n){
    int max=arr[0];
    int min=arr[0];

    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
        
        if(arr[i]<min)
            min=arr[i];
    }

    cout<<max<<" "<<min<<endl;
}

void swap(int *a ,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(int* arr,int n){
    int i=0;
    int j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int findMissingNumber(int *arr,int n){
    int hash[n];
    for(int i=0;i<n;i++){
        hash[arr[i]-1]=1;
    }

    for(int i=0;i<n;i++){
        if(hash[i]!=1){
            return i+1;
        }
    }

    return -1;


}
int findMissingNumber2(int arr[], int n) {
    int sum_of_first_n_numbers = n * (n + 1) / 2;
    int sum_of_array_elements = 0;
    for (int i = 0; i < n - 1; i++) {
        sum_of_array_elements += arr[i];
    }
    return sum_of_first_n_numbers - sum_of_array_elements;
}

void findRepeatNumber(int arr[], int n) {
    int hash[n]={0};
    for(int i=0;i<n;i++){
        if(hash[arr[i]-1]==1){
            hash[arr[i]-1]=2;
        }
        if(hash[arr[i]-1]==0){
            hash[arr[i]-1]=1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(hash[i]>1){
           cout<< i+1 <<" ";
        }
    } 
}

int* merge2sortedArrays(int *arr1,int n1,int *arr2,int n2){
    int* arr3=new int(n1+n2);
    int k=0,i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr3[k++]=arr1[i++];
    }

    while(j<n2){
        arr3[k++]=arr2[j++];
    }

    return arr3;
}

void rotateArray(int* arr, int n, int k) {
    int* temp = new int[k];

    // Copy the last k elements to a temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy the temporary array to the beginning of the original array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    delete[] temp; // Don't forget to free the memory
}

int main(){
    int arr[5]={1,2,4,5,8};
    int arr1[5]={2,6,9,10,11};
    //cout<<Linear_search(arr,5,10)<<endl;
    //max_min_array(arr,5);
    //reverse(arr,5);
    //for(int i=0;i<5;i++){
        //cout<<arr[i]<<" ";}

    //cout<<findMissingNumber2(arr,8);
    //findRepeatNumber(arr,8);

    //int *arr2=merge2sortedArrays(arr,5,arr1,5);

    rotateArray(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}