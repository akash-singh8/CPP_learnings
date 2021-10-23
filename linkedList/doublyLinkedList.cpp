#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev = NULL;
        int data;
        Node* next = NULL;

        Node(int data){
            this->data = data;
        }
};

// Function to print the doubly linked list
void print(Node* head){
    while (head->next!=NULL){
        cout<<head->data<<" <--> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}

// Function to take input of doubly linked list
Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL, *tail=NULL;
    while (data!=-1){
        Node* newNode = new Node(data);
        if (head==NULL) head = newNode;
        else{
            newNode->prev = tail;
            tail->next = newNode;
        }
        tail = newNode;
        cin>>data;
    }
    return head;
}

// Function to delete doubly linked list
void deleteDll(Node *head){
    while (head!=NULL){
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}

// Insert node in doubly linked list at ith index
Node* insertNode(Node *head, int i, int data){
    Node *curr = head;
    Node *newNode = new Node(data);
    if (i==0){
        newNode->next = curr;
        curr->prev = newNode;
        return newNode;
    }
    while(i-->1) curr=curr->next;
    if (curr->next!=NULL) curr->next->prev = newNode;
    newNode->next = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}

// delete node at ith index in double linked list
Node* delNodeAtI(Node* head, int i){
    if (i==0){
        Node *temp = head->next;
        temp->prev = NULL;
        delete head;
        return temp;
    }   
    Node *curr = head;
    while (i-->1) curr = curr->next;
    Node *temp = curr->next;
    curr->next = temp->next;
    if (temp->next!=NULL) temp->next->prev = curr;
    delete temp;
    return head;
}

int main(){

    Node *head = takeInput();
    print(head);

    int i;
    cin>>i;
    head = insertNode(head, i, 49);
    print(head);

    head = delNodeAtI(head, i);
    print(head);

    deleteDll(head);
    return 0;
}