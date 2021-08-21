#include <iostream>

using namespace std;

// Program to find Ceiling(Smallest No. greater than or equal to) num from an given sorted Array
// Using Linear Search:
void ceilingNumbLS(char arr[], int size, char target){
    for (int i=0; i<size; i++){
        if (arr[i]>target){
            cout<<"Ceiling Number : "<<arr[i]<<" at Index : "<<i<<endl;
            break;
        }
    }
}


// Using Binary Search: 
void ceilingNumbBS(char arr[], int size, char target){
    int start=0, end = size-1, mid;
    bool isPresent=false;
    if (target>arr[size-1]){
        cout<<"Please Enter a Number in range!"<<endl;
        exit;
    }
    while (start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid + 1;
        }
        else if (target<arr[mid]){
            end = mid - 1;
        }
        else{
            cout<<arr[mid]<<" at "<<mid<<endl;
            isPresent = true;
            break;
        }
    }
    if (!isPresent){
        cout<<arr[start]<<" at "<<start<<endl;
    }
}


// Program to find the floor(greatest no. less than/euqal to target num) num from an Sorted array
// Using Linear Search
void floorNumLS(int arr[], int size, int target){
    int prevNum, prevInd;
    for (int i=0; i<size; i++){
        if (arr[i]>target){
            prevNum = arr[i-1];
            prevInd = i - 1;
            break;
        }
    }
    cout<<"Floor Number : "<<prevNum<<" at Index : "<<prevInd<<endl;
}

// Using Binary Search
void floorNumBS(char arr[], int size, char target){
    int start=0, end=size-1, mid;
    bool isPresent = false;
    while (start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid + 1;
        }
        else if (target<arr[mid]){
            end = end - 1;
        }
        else{
            cout<<arr[mid]<<" at "<<mid<<endl;
            isPresent = true;
            break;
        }
    }
    if (!isPresent){
        cout<<arr[end]<<" at "<<end<<endl;
    }
}


// Program to find the last and first position of element in sorted array
// Using linear Search - Time Complexity : O(n)
void fstLastOcc(int arr[], int size, int target){
    bool fstOcc = true;
    int fstOccInd=-1, lstOccInd=-1;
    for (int i=0; i<size; i++){
        if (target==arr[i] && fstOcc){
            fstOccInd = i;
            fstOcc = false;
        }
        if (target==arr[i]){
            lstOccInd = i;
        }
    }
    cout<<"First Occurance : "<<fstOccInd<<" and Last Occurance : "<<lstOccInd<<endl;
}

// Using Binary Search - Time Complexity : O(logn)
void fstOcc(int arr[], int size, int target){
    int start=0, end=size-1, mid, fstOccInd;
    while(start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid+1;
        }
        else if (target<arr[mid]){
            end = mid - 1;
        }
        else{
            break;
        }
    }
    while(start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid+1;
        }
        else if (target<arr[mid]){
            end = mid - 1;
        }
        else{
            fstOccInd = mid;
        }
    }
}


// Program to find position of an element in infinite sorted array
int findPosition(int arr[], int target){
    int start=0, end=1, mid;
    while (target>arr[end]){
        int temp = end + 1;
        end = end + (end-start+1)*2;  // end-start is the size of current box.
        start = temp;
    }

    while (start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid + 1;
        }
        else if (target<arr[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}


// Program to find peak index in a mountain array
// using Linear Search
int peakIndexLS(int arr[], int size){
    int peak = arr[0], peakInd;
    for (int i=0; i<size-1; i++){
        if (arr[i+1]>peak){
            peak = arr[i+1];
        }
        else{
            peakInd = i;
            break;
        }
    }
    return peakInd;
}

// Using Binary Search
int peakIndexBS(int arr[], int size){
    int start=0, end=size-1, mid;
    while (start<end){
        mid = (start+end)/2;
        if (arr[mid]>arr[mid+1]){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}


// Program to search for the element in mountain array
// Ofcourse using Binary Search
// My BruteForce Approach using binary search - first fine the peak index and then binary search on both of the halfes.
int findInMA(int arr[], int size, int target){
    int start=0, end=size-1, mid;
    while (start<end){
        mid = (start+end)/2;
        if (arr[mid]>arr[mid+1]){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    start = 0;
    int temp = end;
    bool isPresent = false;
    while (start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid + 1;
        }
        else if (target<arr[mid]){
            end = mid - 1;
        }
        else{
            isPresent = true;
            return mid;
        }
    }
    start = temp+1, end = size-1;
    if (!isPresent){
        while (start<=end){
            mid = (start+end)/2;
            if (target>arr[mid]){
                end = mid -1;
            }
            else if (target<arr[mid]){
                start = mid + 1;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}


// Program to search in rotated sorted array : Rotated sorted array are those which has been rotated at some particular index
// We can easliye solve it with Linear Search approach but as it's an Sorted array Binary Search approach will be much better which'll have Time Complexity of O(logn)
// First approach: Finding the pivot in the array and applying binary search on Both halfes.
int srchItemInRSA(int arr[], int size, int target){
    // Finding the pivot index
    int start=0, end=size-1, mid;
    while (start<end){
        mid = (start+end)/2;
        if (arr[start]>=arr[mid]){
            end = mid;
        }
        else if (arr[mid]>arr[end]){
            start = mid;
        }
    }
    
    int temp = mid;
    if (target>=arr[0]){
        // Applying Binary Search in first half
        start = 0, end = mid;
    }
    else if (target == arr[mid]){
        return mid;
    }
    else if (target<start){
        // Applying Binary Search in second half
        start = temp+1, end = size-1;
    }
    else{
        return -1;
    }
    while (start<=end){
        mid = (start+end)/2;
        if (target>arr[mid]){
            start = mid + 1;
        }
        else if (target<arr[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
}

// Program to count how many time an array is rotated
int coutRA(int arr[], int size){
    // Finding the pivot index
    int start=0, end=size-1, mid;
    while (start<end){
        mid = (start+end)/2;
        if (arr[start]>=arr[mid]){
            end = mid;
        }
        else if (arr[mid]>arr[end]){
            start = mid;
        }
    }
    return mid+1;
}


// Program to split array's largest sum, given an integer m, i.e. we can split the array into m non-empty continious sub array  e.g. arr=[7, 2, 5, 8, 10] & m=2, we've to split the array in two parts and after finding the max sum btw those two arrays we've to compare all the maximum's sum and then output the minimum of those.
 


int main(){
    // char target;
    // cin>>target;
    // char array[7] = {'a', 'b', 'c', 'e', 'f', 'i', 'k'};
    // ceilingNumbBS(array, 7, target);
    // floorNumBS(array, 7, target);

    // int arr[8] = {5, 7, 7, 7, 7, 8, 8, 10};
    // fstLastOcc(arr, 8, 7);
    // fstOcc(arr, 8, 7);

    // int arr[] = {2, 3, 5, 6, 7, 8, 10, 11, 12, 15, 20, 23, 30, 31, 37, 39, 40};
    // int num;
    // cin>>num;
    // cout<<findPosition(arr, num)<<endl;

    // int mArr[9] = {1, 4, 8, 9, 7, 5, 3, 2 ,1};
    // cout<<peakIndexBS(mArr, 9)<<endl;
    // cout<<findInMA(mArr, 9, 2)<<endl;


    int nums[8] = {3, 4, 5, 6, 7, 0, 1, 2};
    cout<<srchItemInRSA(nums, 8, 6)<<endl;
    cout<<coutRA(nums, 8)<<endl;

    return 0;


}
