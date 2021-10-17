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

// Function to find length of linked list
int lenLL(Node *head){
    int size = 0;
    while (head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

// Function to find the data of ith node in linked list
int ithNode(Node *head, int i){
    int curr = 0;
    while (head != NULL){
        if (i==curr){
            return head->data;
        }
        curr++;
        head = head->next;
    }
    return -1;
}


// Function to insert new node at ith index in linked list
void insertNode(Node *head, int index, int data){
    if (index<0 || index > lenLL(head)){
        cout<<"OUT OF RANGE!"<<endl;
        return;
    }
    int currentInd = 0;
    Node *newNode;
    Node *currNode = head;
    if (index == 0){
        newNode = new Node(head->data);
        head->data = data;
    }
    else newNode = new Node(data);
    while (currentInd < index-1){
        currNode = currNode->next;
        currentInd++;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
}

// Delete node at ith index on linked list
void removeNode(Node *head, int i){
    int len = lenLL(head);
    if (i<0 || i>=len){
        cout<<"OUT of Range!"<<endl;
        return;
    }
    if (i == 0 && len>1){
        head->data = head->next->data;
    }
    int currInd = 0;
    Node *currNode = head;
    while (currInd < i-1){
        currNode = currNode->next;
        currInd++;
    }
    Node *a = currNode->next;
    if (i == len-1) currNode->next = NULL;
    else currNode->next = currNode->next->next;
    delete a;
}

// function to rotate the linked list
Node *rotateLL(Node *head, int n){
    Node *prevHead = head;
    int currInd = 0;
    Node *newHead = NULL;
    while (head->next != NULL){
        if (currInd == n-1){
            newHead = head->next;
            head->next = NULL;
            head = newHead;
        }
        head = head->next;
        currInd++;
    }
    head->next = prevHead;
    return newHead;
}


// Remove consecutive duplicates from an linked list
void removeCduplicates(Node *head){
    Node *curr = NULL;
    while (head->next != NULL){
        if (curr!=NULL && curr->data!=head->data){
            curr->next = head;
            curr = NULL;
        }
        if (curr==NULL && head->data==head->next->data){
            curr = head;
        }
        head = head->next;
    }
    if (curr != NULL){
        if (curr->data == head->data) curr->next = NULL;
        else curr->next=head;
    }
}

// Check if the given linkedlist is palindrome or not
bool isPalindrome(Node *head){
    if (head == NULL || head->next==NULL) return true;
    int n = lenLL(head);
    Node *temp = head;
    int arr[n];
    for (int i=0; temp!=NULL; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }
    for (int i=n-1; i>=0; i--){
        if (arr[i]!=head->data){
            return false;
        }
        head = head->next;
    }
    return true;
}

int main(){
    Node *head = takeInput();
    printLL(head);

    cout<<lenLL(head)<<endl;
    // cout<<ithNode(head, 0)<<endl;
    // insertNode(head, 1, 43);
    // printLL(head);

    // removeNode(head, 0);
    // printLL(head);

    // head = rotateLL(head, 2);
    // printLL(head);
    // removeCduplicates(head);
    // printLL(head);

    cout<<isPalindrome(head)<<endl;

    return 0;
}