#include <iostream>
using namespace std;

/* Before Studying Linked List lets understand the limitation of array, so the problem with array is it's size should be fixed
    before compiling due to which we can't add more elements to it and the reason behind it is while the array is created it 
    does take contiguous memory location in memory, due to which even if we can add elements to it & suppose the lastItem+1 
    memory address is filled with another data, so the whole array has to be shifted to other memory location just to add  
    some item. And another problem is to insert an item at 0th index in array it take O(n) operations.
   
   Whereas in Linked List all the items are stored at different memory location because of this property we can easliy add more 
   data to it, as all the items are present at different memory location it's doesn't have any problem like arrays, and one more 
   benefit with LL is we can eaily insert an item in LL which will take O(1) operation. There's only one problem with Linked List
   is to access the items as in array the items are present at contiguous memory location it's easy to access, but in LL it's 
   not the case, means we've to use another variable to store the address of the next node due to which the space taken by LL 
   will be more, compare to array.

   Linked List : It's an Data Structure which consisits of node present at different memory location & they are linked to each 
    other, whereas a node consists of two thing i> Data and ii> Address of next node.
    -> The first node of Linked List is called Head & the last one is called Tail

    So to create a LL we have to create a Node and for that we uses Class's object which represents a node in LL, since there 
    not any datatype which can contain data and address at same time, so we create our own like dataType using class.
*/

class Node{
    public : 
        int data;
        Node *next = NULL;

        Node(int data){
            this->data = data;
        }
};

void print(Node *head){
    while(head->next != NULL){          // We can also use head!=NULL as condition to print whole LL in one shot
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}

int main(){
    // Creating LL using Static memory allocation
    Node n1(5);
    Node *head = &n1; // it's just an pointer variable not a Node, means it'll just store the address of Node dataType var

    Node n2(6);
    n1.next = &n2;
    Node n3(8);
    n2.next = &n3;

    print(head);
    cout<<head->data<<endl;  // the head will still point to LL's head as we didn't pass it by reference

    // Creating LL using Dynamic memory Allocation (Heap)
    Node *np1 = new Node(10);
    Node *np2 = new Node(13);
    // Currently np1 is the pointer pointing to the address of Node's object creating in Heap memory which has two thing data and next -> pointing to null, so let's point the next to next's node address
    np1->next = np2;           // (*np1).next = np2 (np2 has the address of n2 pointer created in Heap Memory)
    Node *headp = np1;
    print(headp);
    delete np1, np2;
    
    return 0;
}