#include<iostream>
using namespace std;
/* Standard Template Library(STL) consists of many functions and classes which is used for some extra features and also saves 
    our time. The Main Components of STL are : Containers and Algorithms
    To learn more about it : https://whimsical.com/c-stl-XVxuHHof5GTWA4NXZhXQhx
*/
// Array class in STL which is basically similar as the main array we do use, it's also a template class which accepts two parameters first is for the dataType of array items and second is for size of the array.
#include<array>

/* Vector class in STL is like an Dynamic Array, the difference is whenever the size is exceded (e.g. the size is 4 but still 
we add item to it) in such cases it automatically doubles it's size by creating a new vector having double size then copying 
all the items to it and dumps the old vector, by the way we don't have to define it's size it automatically adjusts it and 
it's also uses template which accepts one parameter which is the dataType of vector  */
#include<vector>


int main(){
    array <int, 4> arr = {1, 4, 9, 8};
    for (int i=0; i<arr.size(); i++){
        cout<<arr.at(i)<<" ";        // we can also do arr[i].
    }
    cout<<endl;
    cout<<"Is array's Empty : "<<arr.empty()<<endl;    // empty() Checks if array is empty or not
    cout<<"First Element : "<<arr.front()<<endl;       // front() returns the first item of array
    cout<<"Last Element : "<<arr.back()<<endl;          // back() returns the last item of array 
    
    vector <int> vec;
    cout<<"capacity -> "<<vec.capacity()<<endl;  //capacity() returns the total space in vector
    vec.push_back(3);
    cout<<"capacity -> "<<vec.capacity()<<endl;
    vec.push_back(5);
    cout<<"capacity -> "<<vec.capacity()<<endl;
    // till now the size of vector is 2, now if we add more item, it doubles it size
    vec.push_back(9);
    cout<<"capacity -> "<<vec.capacity()<<endl;
    cout<<"Occupied Space : "<<vec.size()<<endl;    // size() returns only the occupied space, 

    // we can use vec[index] or vec.at[index] to access some item of vector, but we can't do same to insert an item
    vec.pop_back();    // pop_back() is used to remove the item from the back
    vec.clear();       // clear() used to clear all the items but the capacity will remain same.

    /* If we know the size, we can also specify the size of vector initially, by passing the size to first parameter of 
    constructor, the second parameter is for the items of vector if we don't pass that it'll be set as 0 by default.  */
    vector <int> vec1(5);
    cout<<"Items of vec1 : "; 
    for (int i=0; i<vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }

    // to copy one vector from another vector, the syntax is : 
    vector <int> cpyVec(vec1);       // cpyVec will copy all the items present in vec1
    cout<<"\ncapacity of cpyVec : "<<cpyVec.capacity()<<endl;
    cout<<"Items of cpyVec : "; 
    for (int i=0; i<cpyVec.size(); i++){
        cout<<cpyVec[i]<<" ";
    }


    return 0;
}