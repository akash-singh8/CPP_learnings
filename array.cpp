/* Array is an data structure which is used to store list of variable having similar dataTypes
    Syntax to initialize an Array : <dataType arrayName[length_of_Array]>;
    Size of an Array in Memory : <sizeOfIndividualVarialbe>*lengthofArray 
    Array stores information in contiguous memory allocation
*/
#include<iostream>

using namespace std;

// Array Searching Algorithms
// Function to perform Linear Search algorithm in an Array. Time Complexity : O(n)
int linearSearch(int arr[],int size, int key){
    for(int index=0; index<size; index++){
        if(arr[index]==key){
            return index;
        }
    }
    return -1;
}

// Function to perform binary search algorithm time complexity: 0(logn) but for it the array should be sorted.
int binarySearch(int arr[], int size, int key){
    int start=0, end=size-1;
    while (start<=end){
        int mid=(start+end)/2;
        if (key>arr[mid]){
            start = mid + 1;
        }
        else if (key<arr[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}


int main(){

    int arr[4] = {5, 8, 7, 3};
    for (int i=0; i<4; i++){
        cout<<arr[i]<<" ";
    }

    // taking user input array 
    cout<<"\nEnter the Size of Array : ";
    int size;
    cin>>size;
    int newArr[size];
    cout<<"Enter the Elements of Array seprated by Space : ";
    for (int j=0; j<size; j++){
        cin>>newArr[j];
    }
    for (int i=0; i<size; i++){
        cout<<newArr[i]<<" ";
    }

    // finding the minimum and maximum item in an Array
    int minNo=newArr[0], maxNo=newArr[1];
    for (int i=0; i<size; i++){
        maxNo = max(maxNo, newArr[i]);
        minNo = min(minNo, newArr[i]);
    }
    cout<<"\nMinimum : "<<minNo<<" and Maximum : "<<maxNo<<endl;

    int key;
    cout<<"Enter a key to search it in Array : ";
    cin>>key;
    cout<<linearSearch(newArr, size, key)<<endl;
    cout<<binarySearch(newArr, size, key);
    

    return 0;
}