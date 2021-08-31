#include <iostream>

using namespace std;

int main(){
    
    /* Whenever we allocate memory there's are generally two types of memory - 1>Stack(generates at compile time - Static 
    Allocation) and 2>Heap(generates at Runtime - Dynamic memory Allocation) whenever we initialize some int, arrays etc. it is 
    stored in the Stack Memory on the compile time the required memory is assigned to variables in stack memory. sometimes we  
    need to create an array at runtime but at that time maybe the given size of array can accede the stack memory! so in such  
    cases Heap Memory can be used.

    Dynamic Memory Allocation
    int i = 10;  this memory will allocate at Stack, but to allocate the memory in Heap new key word is used.
    new int; This will create an memory/storage in Heap memory, but we can't assign any name to this address like we do 
    previously i.e. int i=10; so the new int; returns the address assined to that integer in heap memory and to storte that 
    address we can use pointers.        */

    int *p = new int;
    /* this will create memory of 4 bytes in HeapMemory and will return an address of that memory to the pointer p and this 
    pointer will stored in Stack Memory and will take 4 bytes as well. So in total 8 bytes is used.*/
    *p = 10;
    // another way to assing the value at the address is : int *p = new int(10);
    cout<<p<<" "<<*p<<endl;


    // Storing an array in Heap memory
    // int *arrp = new int[10]; as we know in case of array the pointer point to the address of first item in array

    // Now we can easiy take size of array from user as this time we are doing Dynamic Memory Allocation.
    int n;
    cin>>n;
    int *parr = new int[n]; 

    parr[0] = 4;  // as parr[0] is same as doing *(parr + 0)
    cout<<*parr<<endl;


    /* In case of Static Memory Allocation(Stack) the memory assigned to variable automatically deallocate at the end of its 
    scope, whereas in Dynamic Memory Allocation(Heap) we've to manually deallocate the memory, and for that we use delete 
    keyword like delete <address>; if we don't deallocate, it'll be always there in Heap Memory and a time will come when it'll 
    get crash. */

    delete p; // Deleting an single element
    delete []parr; // for Deleting an whole Array a [] is used 

    // p or parr will not be deleted! The memory which it's pointing to will be deleted.s
    cout<<*parr; // it'll give an garbage value as the value at address stored in it has been deleted!
    
    /* Dynamic Memory Allocation of 2D Arrays : 
     to store 2D arrays dynamically we can't use net int[5][10], so then to create an 2d array first we create an array(pointer array) in Heap Memory in which we storest the address of other arrays by using pointers
    */
    int **parr2 = new int*[5];  // this will create an array which stores the address of 5 items using pointer and later on we can used it to point to another array

    for (int i=0; i<5; i++){
        parr2[i] = new int[5];  // parr2[i]->*(parr2+i) it will create an new array at each index of pointer array 
    }

    // to Delete an Dynamic 2d array
    // by doing delete parr2; it'll only delete the array which consists of addresses of another array.
    // so first we've to delete all the array in pointer array, to do so we can use it address sotred in parr2
    for (int i=0; i<5; i++){
        delete [] parr2[i];
    }
    delete [] parr2;


    return 0;
}