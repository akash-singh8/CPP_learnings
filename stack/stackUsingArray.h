#include<iostream>

using namespace std;

/* Stack is a linear data structure which is of Abstract data type mean all the operation like insertion, deletion, 
accessing.... can be performed only in some specific order, in case of Stack as it follows Last In First Out (LIFO) all the 
operation can be only performed on one end of the stack which is called top of the stack 
Operation related to Stack : 
1. Insertion -> Push : used to insert item in stack
2. Deletion -> Pop : delete and returns the top item in the stack
other operation like top(), size() and isEmpty().                */

// Also we're using templates, so that Stack of any dataType can be created...
template<class dT>
class Stack{
    // int stk[50]; since we don't know the actual size of arr, we've to create it dynamically
    dT *stk;
    int len;
    int ind = 0;
    public:
        Stack(int size){
            len = size;
            stk = new dT[len];
        }

        void push(dT data){
            if (ind == len){
                /* Making the Stack dynamic - means as it get full double the size of it, so that we don't have to worry about it's size
                int *newStk = new int[len*2];
                for (int i=0; i<ind; i++){
                    newStk[i] = stk[i];
                }
                len *= 2;
                delete []stk;
                stk = newStk; */
                cout<<"Stack OverFlow!"<<endl;
                return;
            }
            stk[ind] = data;
            ind++;
        }
        
        bool isEmpty(){
            return ind == 0;
        }

        dT pop(){
            if (isEmpty()){
                cout<<"Stack UnderFlow!"<<endl;
                return 0;
            }
            ind--;
            return stk[ind];
        }

        dT top(){
            if (isEmpty()){
                cout<<"Stack's Empty!"<<endl;
                return 0;
            }
            return stk[ind-1];
        }

        int size(){
            return ind;
        }

        void printStack(){
            cout<<endl;
            for (int i=ind-1; i>=0; i--){
                cout<<" |  "<<stk[i]<<"  | "<<endl;
                cout<<" '-----'"<<endl;
            }
        }

        // Creating a Destructor to deallocate the stack from dynamic memory
        ~Stack(){
            delete []stk;
        }
};

