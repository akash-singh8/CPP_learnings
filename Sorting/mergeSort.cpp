#include<iostream>
using namespace std;
/*
  Merge Sort Algorithm
    -> Merge Sort is a Divide and Conquer Algorithm.
    -> It divides input array in two halves, calls itself for two halfs(recursively) and then merges two sorted halves.
    -> A separate merge function is used for merging two halves
*/


void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[r-l+1];
    while (i<=m && j<=r){
        if (arr[i]>arr[j]){
            temp[k] = arr[j];
            j++;  
        }
        else{
            temp[k] = arr[i];
            i++;
        }
        k++;
    }
    while (i<=m){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j<=r){
        temp[k] = arr[j];
        j++;
        k++;
    }
    k=0;
    for (int i=l; i<=r; i++){
        arr[i] = temp[k];
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l<r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int main(){
    int arr[9] = {3, 4, 7, 8, 9, 2, 3, 5, 7};
    for (int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, 0, 8);
    for (int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}