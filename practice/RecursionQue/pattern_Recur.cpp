#include<iostream>

using namespace std;

/* Write Recursive function to print given pattern 
1. * * * *
   * * *
   * *
   *                                               */
void pattern1(int n, int i=0){
    if (n == 0){
        return;
    }
    if (n == i){
        cout<<endl;
        pattern1(n-1, 0);
        return;
    }
    cout<<"* ";
    pattern1(n, i+1);
}

/* 2.  *
       * *
       * * * 
       * * * *           */
void pattern2(int r, int c=0){
    if (r == 0){
        return;
    }
    if (r == c){
        pattern2(r-1, 0);
        cout<<endl;
        return;
    }
    pattern2(r, c+1);
    cout<<"* ";
}

// Bubble Sort using recursion it's same as the 1 question
void bubbleSort(int arr[], int size, int i=0){
    if (size <= 1){
        return;
    }
    if (size-1 == i){
        bubbleSort(arr, size-1, 0);
        return;
    }
    if (arr[i]>arr[i+1]){
        swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, size, i+1);
}

// Selection sort using Recursion
// Let's first write recursive program to find the index of minimum item in array
int minItem(int arr[], int size, int min=2389){
    if (size == 0){
        return -1;
    }
    if (arr[0] < min){
        return 1 + minItem(arr+1, size-1, arr[0]);
    }
    return minItem(arr+1, size-1, min);
}
void selcSort(int arr[], int size){
    if (size == 0){
        return;
    }
    swap(arr[0], arr[minItem(arr, size)]);
    selcSort(arr+1, size-1);
}

// Let's do Selection Sort in one shot
void selectionSort(int arr[], int size, int i=0, int maxInd=0){
    if (size <= 1){
        return;
    }
    if (size == i){
        swap(arr[size-1], arr[maxInd]);
        selectionSort(arr, size-1, 0, 0);
        return;
    }
    if (arr[i]>arr[maxInd]) selectionSort(arr, size, i+1, i);

    else selectionSort(arr, size, i+1, maxInd);
}


int main(){

    pattern1(3);
    pattern2(3);
    cout<<endl;

    int arr[5] = {4, 2, 1, 7, 5};
    // bubbleSort(arr, 5);
    // selcSort(arr, 5);
    selectionSort(arr, 5);
    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}