#include<iostream>
using namespace std;

/* So let's start with what we need to use that new shit, basically it's like dictionary in python which we know how useful
    it is, like in array the key/index can only be of integer type but we want something in which the key can be of any
    datatype like name so that it's easier to search and to use, So a hashmap consists of only three function that is 
    Insert(key, value) -> insert key with the given value only if the key is unique,
    Search(key) -> returns the value corresponding to given key and delete -> deletes the value and key 
    
    There are many ways to implement an Hashmap like one way to use Linked list in which the node will consists of key, value
    and next's address but the Time complexity of all hashmap operation in it will be O(n) which is not great and another way
    is to use Binary Search tree which will be balanced(AVL tree) but still the time complexity for all the operations will 
    be O(logn) which is better that using linked list but still it can be optimized .*/

/* First let's see the inbuilt map, which is implemented using a BST(AVL) due the which all the key-value pairs stored in it 
    are in ordered manner so we can access all the pairs in sorted order by doing traversing it in Inorder & all the operation 
    of it will have time complexity O(log) & there's another inbuilt file unordered_map which is implemented using Hashtable 
    thus the time complexity of all the operations in it will be O(1)  */

// #include<map>     it's like ordered Map as it's implemented using balance BST
#include<unordered_map>



int main(){
    unordered_map<string, int> uMap;
    // map and unordered_map are uses template which accepts two datatype as parameter one's for key & other for value

    // One way to insert in maps using insert function which accepts a pair as parameter
    pair<string, int> p("Akash", 18);
    uMap.insert(p);

    // Another way to insert in maps, and if the given key already it's value will be updated with given key value
    uMap["Elon"] = 43;

    // accessing value using at function
    cout<<uMap.at("Elon")<<endl;

    // The problem with accessing value like this, is if the given key isn't present it'll insert a new key and assign it's value as 0 & will return 0
    cout<<uMap["Akash"]<<endl;

    // Check presence of the key using count function as in map a count can't be present more than once
    if (uMap.count("Akash")) cout << "Present" << endl;

    cout << "Size : " << uMap.size() <<endl;

    // Removing an key-value pair from map
    uMap.erase("Elon");
    cout << "Size : " << uMap.size() <<endl;

    return 0;
}