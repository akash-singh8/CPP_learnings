#include <iostream>

using namespace std;

// 1. Given an array containing n distinct number in the range [0, n], return the missing number
int missingNum(int arr[], int size){
    int i=0;
    while (i<size){
        if (arr[i]==size || arr[i]==i){
            i++;
        }
        else{
            int temp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = temp;
        }
    }
    for (i=0; i<size; i++){
        if (arr[i]!=i){
            return i;
        }
    }
    return i;
}


//2. Given an array of n integers in the range[1, n] return an array containing all elements which are in range [1, n] and not present in the array
void findMissing(int arr[], int size){
    int i=0;
    while (i<size){
        int correct = arr[i]-1;
        if (arr[i]!=arr[correct]){
            int temp = arr[correct];
            arr[correct] = arr[i];
            arr[i] = temp;
        }
        else{
            i++;
        }
    }

    for (i=0; i<size; i++){
        if (arr[i]!=i+1){
            cout<<i+1<<" ";
        }
    }
}


//3. Given an array of integers containing n+1 integers all in the range [1, n], find the duplicate/repeated one.
int findRepeated(int arr[], int size){
    int i=0;
    while (i<size){
        int correct = arr[i]-1;
        if (arr[i]!=arr[correct]){
            int temp = arr[correct];
            arr[correct] = arr[i];
            arr[i] = temp;
        }
        else{
            i++;
        }
    }
    return arr[size-1];
}


//4. Given an array of n integers all in the range [1, n], find the number that occurs twice and the number that is missing
void findDM(int arr[], int size){
    int i=0;
    while (i<size){
        int correct = arr[i]-1;
        if (arr[i]!=arr[correct]){
            int temp = arr[correct];
            arr[correct] = arr[i];
            arr[i] = temp;
        }
        else{
            i++;
        }
    }

    for (i=0; i<size; i++){
        if (arr[i]!=i+1){
            cout<<"Duplicate : "<<arr[i]<<endl;
            cout<<"Missing : "<<i+1<<endl;
        }
    }
}


//5. Given an integer array, return the smallest missing positive integer
int findMissPositive(int arr[], int size){
    int i = 0;
    while (i<size){
        int correct = arr[i]-1;
        if (arr[i]!=arr[correct] && arr[i]>0 && arr[i]<=size){
            int temp = arr[correct];
            arr[correct] = arr[i];
            arr[i] = temp;
        }
        else{
            i++;
        }
    }

    for (i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for (i=0; i<size; i++){
        if (arr[i]!=i+1){
            return i+1;
        }
    }
    return i;
}

int main(){
    int array[5] = {7,8,9,11,12};
    cout<<findMissPositive(array, 5);
    return 0;
}
