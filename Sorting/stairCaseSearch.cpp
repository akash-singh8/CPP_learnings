#include<iostream>

using namespace std;

int main(){

    /* StairCase Search ; used to search in a 2d array which is sorted rows as well as column wise;
    if 2D array is sorted only rows wise then we should used Binary search to searh in every row one by one which may take O
    (nlogn), and if the 2D array is not sorted in any way then we should use basic Linear Search.
    */
    int arr[4][4] = {{1, 4, 8, 10}, {2, 5, 9, 15}, {6, 16, 18, 20}, {11, 17, 19, 23}};
    int *ptr = &arr[0][3];
    int target = 17;
    while (*ptr != target){
        if (target<(*ptr)){
            ptr--;
        }
        else{
            ptr += 4;
        }
        cout<<*ptr<<" ";
    }

    return 0;
}