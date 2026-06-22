#include <stdio.h>
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

void Insert(int arr[],int n){
  int j;
  for(int i=1;i<n;i++){
    int temp=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>temp){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=temp;
  }
}

void bubbleSortRecursive(int arr[], int n) {
  // Base case: If there's one or zero elements, it's already sorted
  if (n == 1)
      return;

  // One pass of bubble sort: move largest to the end
  for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1])
          swap(arr[i], arr[i + 1]);
  }

  // Recursive call for the remaining array
  bubbleSortRecursive(arr, n - 1);
}

void insert(int arr[], int n) {
  int key = arr[n - 1];
  int j = n - 2;

  // Move elements greater than key one position ahead
  while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
  }
  arr[j + 1] = key;
}

// Recursive function to sort the array
void recursiveInsertionSort(int arr[], int n) {
  // Base case: if size is 1 or less, it's already sorted
  if (n <= 1)
      return;

  // Recursively sort first n-1 elements
  recursiveInsertionSort(arr, n - 1);

  // Insert last element at its correct position in sorted array
  insert(arr, n);
}

void Selection(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int min_index=i;
    for(int j=i+1;j<n;j++){
      if(arr[min_index]>arr[j]){
        min_index=j;
      }
    }
    if (min_index!=i){
      int temp=arr[min_index];
      arr[min_index]=arr[i];
      arr[i]=temp;
    }
  }
}


int main(){
  /*
  int A[6]={40,67,11,9,18,28};
    printf("Original ARRAY \n");
    for(int i=0;i<6;i++){
        printf("%d  ",A[i]);
    }
    Bubble(A,6);
    printf("\nSORTED ARRAY \n");
    for(int i=0;i<6;i++){
        printf("%d  ",A[i]);
    }*/
   
    return 0;
  }
