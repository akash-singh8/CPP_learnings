#include<iostream>

using namespace std;

// Passing pointers to function: It's the main use of pointers since any argument we pass to the function the actual vaule of it doesn't get update, as a function create a local variable in itself, so with pointers a function will get main address of value which we want to update and it'll get updated.
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void increment(int *num){
    *num += 1;
}

int main(){

    // Pointer are variable that stores the address of other variable.
    // Pointer is an datatype which is used to store the address of an variable, as it's in Hexadecimal format e.g 0x61ffc so integer & string can't be used to store that address, so a data type i.e pointer is created to store that! and in memory if an integer takes 4bytes(in continuous order) then it's address will point to first byte as every byte has an unique address  <dataType> *<pointerName> is used to create an pointer which will only stores the address of given dataType as well as it's also used to access the value at the address stored in pointer!   while adding an number to pointer e.g. int *p = &x; ->  *p += 1; it'll increment by 4 bytes in case of int, so in an array if a item is present at address 4 and a pointer is linked to it, so *p += 1; will go to address 8 and stores that address which has value next to previous .


    int arr[5] = {2, 4, 8, 9, 3};
    // in case of array, it's name is a pointer in itself(but a constant pointer), means it stores the address of item at 1st index present in array! so we don't need to use &<arrName> to get it's address, conclusion: arrName => $arrName[0] !
    int *p = arr; // it's pointer which will store the address of only integer data types!

    cout<<p++<<endl;
    cout<<p++<<endl;
    cout<<*p<<endl;

    // print all elements of array
    for (int i=0; i<5; i++){
        cout<<*(arr+i)<<" ";  // as it's arr (constant pointer) use can't update itself means we can't do arr++
    }
    cout<<endl;

    // Double star pointers e.g. int **p; is used to store the address of pointers, in this case it'll store the address of     integer pointer which already stores address of an integer!
    int a = 10;
    int *pa = &a;
    cout<<pa<<endl;

    int **ppa = &pa;
    cout<<*ppa<<endl;

    int x=4, y=5;
    // swap(x, y); // it's will not swap because it only passes it's value to function, that's why we use pointers
    int *px = &x, *py = &y;
    swap(px, py); // it'll work as it passes the address of variable to function!
    cout<<x<<" "<<y<<endl;

    increment(&x);
    cout<<x;

    return 0;
}