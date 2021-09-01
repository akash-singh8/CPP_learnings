#include <iostream>

using namespace std;

/* In this cyclic sort Algorithm the condition is all the elements are in the range of 1<->n(size of array), so by common sense
    the element of array should be at the index element-1, to do this first we'll place the 1st item at it's correct position
    means (itemInd should equal to item-1) and if it's placed at correct position we'll move to next item and do same..
    the time Complexity of Cyclic Sort under this condition is O(n+n-1) -> O(n), as n operation will occur by while loop in 
    iterating over all elements and (n-1) operation will be occur by if-condition inside while loop if the item is not at it's
    correct position.
*/

int * cyclicSort(int arr[], int size){
    int i=0;
    while (i<size){
        if (arr[i]-1!=i){
            int temp = arr[arr[i]-1];
            arr[arr[i]-1] = arr[i];
            arr[i] = temp;
        }
        else{
            i++;
        }
    }
    return arr;
}

int main(){
    int array[5] = {3, 5, 2, 1, 4};
    int *p = cyclicSort(array, 5);
    for (int i=0; i<5; i++){
        cout<<*(p+i)<<" ";
    }
    
    return 0;
}