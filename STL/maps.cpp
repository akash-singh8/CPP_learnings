#include<iostream>
#include<map>
/* list is an Container in Standard Template and it's similar as doubly Linked List(means an item in a list consists of three things 1. Memory 
address of previous item, 2>Item's Data and 3> Memory address of next item, It's peforms insertion and deletion of item more efficiently than 
arrays and vectors)  */

/* Map is also an container in STL and it's similar as HashMap and dictionay in Python, means a Map contains key-value pairs with unique keys.
*/
using namespace std;

int main(){
    map<string, int> marks;   // the template of map take two parameter first is for the dataType of key and second is datatype of value;
    marks["Akash"] = 82;
    marks["Elon"] = 99;
    marks["Jeff"] = 89;
    marks["Bill"] = 100;
    map<string, int> :: iterator iter;
    for (iter=marks.begin(); iter!=marks.end(); iter++){
        // first returns the key of map and second returns the value associated to that key in the map.
        cout<<(*iter).first<<" : "<<(*iter).second<<endl;
    }

    

    return 0;
}