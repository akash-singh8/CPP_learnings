/* Array is an data structure which is used to store list of variable having similar dataTypes
    Syntax to initialize an Array : <dataType arrayName[length_of_Array]>;
    Size of an Array in Memory : <sizeOfIndividualVarialbe>*lengthofArray 
    Array stores information in contiguous memory allocation
*/
#include<iostream>

using namespace std;

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
    cout<<"\nMinimum : "<<minNo<<" and Maximum : "<<maxNo;

    return 0;
}