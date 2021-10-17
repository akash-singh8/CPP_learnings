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

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = 0;
    Node *tail = 0;
    while (data != -1){
        Node *n = new Node(data);
        if (head == 0){
            head = n;
        }else{
            tail->next = n;
        }
        tail = n;
        cin >> data;
    }
    return head;
}

void printLL(Node *head){
    while (head->next != 0){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}


Node* merge(Node* head1, Node* head2){
    Node *head=NULL, *temp, *prev;
    while(head1!=NULL && head2!=NULL){
        if (head1->data < head2->data){
            temp = new Node(head1->data);
            head1 = head1->next;
        }else{
            temp = new Node(head2->data);
            head2 = head2->next;
        }
        if (head == NULL) head=temp;
        else prev->next = temp;
        prev = temp;
    }
    while(head1!=NULL){
        temp = new Node(head1->data);
        prev->next = temp;
        prev = temp;
        head1 = head1->next;
    }
    while(head2!=NULL){
        temp = new Node(head2->data);
        prev->next = temp;
        prev = temp;
        head2 = head2->next;
    }
    return head;
}

// IN this merge function we are not creating any new linked list, we're just connecting both of them to each other.
Node* mergeT(Node* head1, Node* head2){
    Node *head=NULL, *tail;
    while (head1!=NULL && head2!=NULL){
        if (head1->data < head2->data){
            if (head==NULL) head=head1;
            else tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }else{
            if (head==NULL) head=head2;
            else tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1!=NULL) tail->next = head1;
    if (head2!=NULL) tail->next = head2;

    return head;
}

// Function to return the address of mid element in linked list
Node* findMid(Node *head){
    if (head->next == NULL){
        return head;
    }
    Node *temp = head->next;
    while (temp!=NULL && temp->next!=NULL){
        head = head->next;
        temp = temp->next->next;
    }
    return head;
}

// Function to Sort linked list using merger sort 
Node* mergeSort(Node *head, Node *tail=NULL){
    if (head->next==NULL){
        return head;
    }
    Node *mid = findMid(head);
    Node *midNext = mid->next;
    mid->next = NULL;
    Node* h1 = mergeSort(head, mid);
    Node* h2 = mergeSort(midNext, tail);
    return merge(h1, h2);
}

int main(){

    Node *head1 = takeInput();
    // Node *head2 = takeInput();
    printLL(head1);
    // printLL(head2);

    // Node *head3 = merge(head1, head2);
    // Node *head3 = mergeT(head1, head2);
    // printLL(head3);
    // printLL(head1);
    // printLL(head2);
    // cout<<findMid(head3)->data<<endl;
    
    head1 = mergeSort(head1);
    printLL(head1);

    return 0;
}