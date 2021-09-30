#include<iostream>
using namespace std;

// The partition function will return the position of the item it has placed to correct position
int partition(int arr[], int l, int r){
    int pos=l;
    for (int i=l+1; i<=r; i++){
        if (arr[l]>arr[i]){
            pos++;
        }
    }
    swap(arr[l], arr[pos]);
    while (l<pos && r>pos){
        if (arr[l]<arr[pos]){
            l++;
        }
        else if (arr[r]>=arr[pos]){
            r--;
        }
        else{
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    return pos;
}

void quickSort(int arr[], int l, int r){
    if (l>=r){
        return;
    }
    int pos = partition(arr, l, r);
    quickSort(arr, l, pos-1);
    quickSort(arr, pos+1, r);
}

int main(){
    int arr[7] = {6, 2, 20, 8, 15, 3, 4};
    // cout<<partition(arr, 0, 6)<<endl;
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}