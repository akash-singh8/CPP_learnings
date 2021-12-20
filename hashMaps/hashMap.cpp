#include<iostream>

using namespace std;

/* In order to create HashMap we have to find an way to store key-value pair, and the best method we've studied so far is 
   to use an array to store key's value as in array the accessing operation is so fast if we knew the index of item
   and to store the value corresponding to given key, first we've to create an valid unique index for that key, and to do
   so there's a function available called hash function.
   
   Hash Function consists of two things i.e. is hash code and compression function, the hash code basically generates an
   random unique integer corresponding to the given key whereas the compression function make it to range from 0 to array's
   size, e.g. to generate hash code for string the best way so far is to multiply each char with some different integer and
   sum them all, like for "abc" the best hash code could be 65*p*3 + 66*p*2 + 67*p*1 where p is some prime number and for
   class's object the best hash code that can generated is by converting it's hexadecimal adderess to decimal.
   And Coming to the Compression function it's so simple as it's has to make the hash code in a range, and for that 
   hashCode % size will easily give an integer in range from 0 - size.
   
   But still their could be a problem of Collision, like let's say for string "abc" the hash code comes out to be 105 and for
   "def" the hashcode is 205, & after it passes through the compression function for both the generated index will be 5,
   means it's colliding.
   
   Collision Handling : When two different keys get the same index in the bucket array through hash function.
    There's Two ways to handle collision : 1> Closed Hashing/Addressing OR Separate Chaining   and   2> Open Addressing
    In closed hasing if two different key gets the same index, so at that index we'll create a linked list and then
    the current key will be assigned as head of linked list, so the bucket array should be of datatype string* or
    int *arr[20].
    Whereas in Open Addressing, just check if the generated index is empty or not, if it's not go to another index and check
    if that's available or not so on..... hi(a) = hf(a) + f(i) -> the ith attempt for a will be the original hf + f(i).
    1> Linear probing : if index 5 isn't present just go to 6 then 7 .... & so on   -> the f(i) = i
    2> Qudratic probing : just check index with exponential growth .... -> the f(i) = i^2
    there's many of others methods for open addressing
    among all these the Separate Chaining is one of the best and easiest method to do, so we'll implement the insert function
    using separate chaining          */

template <typename valueDt>
class Node{
    public:
        string key;
        valueDt value;
        Node<valueDt> *next = NULL;

        Node(string key, valueDt value){
            this->key = key;
            this->value = value;
        }

        ~Node(){
            delete next;
        }
};

template <typename valueDt>
class hashmap{
    int length;
    int bucketSize;
    Node<valueDt> **bktArr;
    int hashFunction(string key){
        int hashCode = 0;
        for (int i=key.length()-1; i>=0; i--){
            hashCode += key[i] * (7*i);
        }
        hashCode = hashCode % bucketSize;     // It'll act as an compression function
        return hashCode;
    }

    void rehash(){
        length = 0;
        bucketSize *= 2;
        Node<valueDt> **temp = bktArr;
        bktArr = new Node<valueDt>*[bucketSize];
        for (int i=0; i<bucketSize; i++){
            bktArr[i] = NULL;
        }
        for (int i=0; i<bucketSize/2; i++){
            Node<valueDt> *curr = temp[i];
            while (curr != NULL){
                insert(curr->key, curr->value);
                curr = curr->next;
            }
            delete temp[i];
        }
        delete [] temp;
    }

    
    public:
        hashmap(){
            length = 0;
            bucketSize = 5;
            bktArr = new Node<valueDt>*[bucketSize];
            for (int i=0; i<bucketSize; i++){
                bktArr[i] = NULL;
            }
        }

    /* Rehashing the insert function so that all of the operations can be done in O(1) and to rehash we just have to maintain
       the load factor i.e. n/b < 0.7 where n->number of enteries & b->size of array    */
        void insert(string key, valueDt value){
            int index = hashFunction(key);
            Node<valueDt> *head = bktArr[index];
            while (head != NULL){
                if (head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            Node<valueDt> *newNode = new Node<valueDt>(key, value);
            newNode->next = bktArr[index];
            bktArr[index] = newNode;
            length++;

            int loadFactor = (length+0.0)/bucketSize;
            if (loadFactor > 0.7) rehash();   
        }


        valueDt search(string key){
            int index = hashFunction(key);
            Node<valueDt> *head = bktArr[index];
            while (head != NULL){
                if (key == head->key){
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }


        valueDt remove(string key){
            int index =  hashFunction(key);
            Node<valueDt> *head = bktArr[index];
            Node<valueDt> *prev = NULL;
            while (head != NULL){
                if (head->key == key){
                    valueDt value = head->value;
                    if (prev!=NULL) prev->next = head->next;
                    else bktArr[index] = head->next;
                    length--;
                    // before deleting the head we've to make it's next null else it'll call recursiove delete on it's next
                    head->next = NULL;
                    delete head;
                    return value;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }

        int size(){
            return length;
        }

        ~hashmap(){
            for (int i=0; i<20; i++){
                /* as it'll can on an object adderess like delete 100 the the destructor of 100 will be called and it'll will 
                delete it's next, and a recursion call will start which will delete the whole hashmap */
                delete bktArr[i];
            }
            delete []bktArr;
        }
};


int main(){
    hashmap<int> map;
    // cout << "Size : " << map.size() << endl;
    // map.insert("Akash", 18);
    // cout << "Size : " << map.size() << endl;
    // cout << map.search("Akash") << endl;
    // map.insert("Akash", 25);
    // cout << map.remove("Elon") << endl;
    // cout << map.remove("Akash") << endl;

    for (int i=0; i<10; i++){
        char temp = '0' + i;
        string key = "abc";
        key += temp;
        map.insert(key, i+1);
    }

    map.remove("abc1");
    map.remove("abc5");

    cout<<"Size : "<<map.size()<<endl;
    for (int i=0; i<10; i++){
        char temp = '0' + i;
        string key = "abc";
        key += temp;
        cout << key << " : " << map.search(key) << endl;
    }

    return 0;
}