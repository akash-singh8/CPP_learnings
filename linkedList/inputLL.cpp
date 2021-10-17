#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next = NULL;

        Node(int data){
            this->data = data;
        }
};

// Create a function which will take LL as input, since it's returning the address of head node, the return type of func should be of Node*
Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1){
        Node *n = new Node(data);
        if (head== NULL) head = n;
        else tail->next = n;
        tail = n;
        cin>>data;
    }
    return head;
}

void printLL(Node *head){
    while (head->next != NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}

int main(){

    Node *head = takeInput();
    printLL(head);
    
    return 0;
}