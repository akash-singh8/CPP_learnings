#include <iostream>
#include <vector>

using namespace std;

// Recursive function to check an array is sorted or not
bool isSortedArr(int *arr, int size){
    if (size <= 1){
        return true;
    }
    return arr[0]<=arr[1] && isSortedArr(arr+1, size-1);
}

// Linear Search using Recursion - searching from last index
int linearS(int arr[], int size, int target){
    if (size == 0){
        return -1;
    }
    if (arr[size-1] == target){
        return size-1;
    }
    return linearS(arr, size-1, target);
}
// forward Linear Search
int linSearch(int arr[], int size, int target, int i=0){
    if (i==size){
        return -1;
    }
    if (arr[i] == target){
        return i;
    }
    return linSearch(arr, size, target, i+1);
    // or insted of lines 28-31, we can also write return (arr[i]==target)? i : linSearch(arr, size, target, i+1);
}
// Return an array consists of all the indexs which is equal to target element by using Linear Search
int * linSearchAll(int arr[], int size, int target, int i=0, int *n=new int[5], int curr=0){
    if (i == size){
        return n;
    }
    if (arr[i] == target){
        n[curr] = i;
        return linSearchAll(arr, size, target, i+1, n, curr+1);
    }
    return linSearchAll(arr, size, target, i+1, n, curr);
}

// Binary Search on rotates sorted array using Recursion!


int main(){

    int arr[7] = {1, 2, 3, 4, 4, 7, 8};
    cout<<isSortedArr(arr, 7)<<endl;

    cout<<linearS(arr, 7, 8)<<endl;
    
    cout<<linSearch(arr, 7, 5)<<endl;

    int *ind = linSearchAll(arr, 7, 4);
    cout<<ind[0]<<" "<<ind[1]<<endl;

    int rotatedArr[8] = {5, 6, 7, 8, 9, 1, 2, 3};

    return 0;
}