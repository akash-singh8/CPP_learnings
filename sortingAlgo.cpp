// Implementing Array's Sorting algorithms 

#include<iostream>

using namespace std;

// Selection Sort Algorithm, Time Complexit : 0(n^2)
void selectionSort(int arr[], int size){
    for (int i=0; i<size; i++){
        int min=i;
        int minVal = arr[i];
        for (int j=i; j<size; j++){
            if (arr[j]<minVal){
                minVal = arr[j];
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
}


// Bubble Sort Algoritm. Time Complexity : O(n^2)
void bubbleSort(int arr[], int size){
    for (int i=1; i<=size; i++){
        for (int j=0; j<size-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// Insertion Sort Algorithm using Forloop. Time Complexity : O(n^2)
// void insertionSort(int arr[], int size){
//     for (int i=1; i<size; i++){
//         int temp = arr[i];
//         int emptyInd=i;
//         for (int j=i-1; j>=0; j--){
//             if (arr[j]>temp){
//                 arr[j+1] = arr[j];
//                 emptyInd = j;
//             }
//         }
//         arr[emptyInd] = temp;
//     }
// }

// Insertion Sort Algorithm using while loop
void insertionSort(int arr[], int size){
    for (int i=1; i<size; i++){
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int main(){

    cout<<"Enter the Size of Array : ";
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter the Elements of Array separated by space : "; 
    for (int i=0; i<size; i++){
        cin>>array[i];
    }

    // selectionSort(array, size);
    // bubbleSort(array, size);
    insertionSort(array, size);

    for (int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}