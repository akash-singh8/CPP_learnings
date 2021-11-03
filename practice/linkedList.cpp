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



// Arrange the linked list in even after odd order
void evenAodd(Node *head){
    if (head==NULL || head->next==NULL) return;
    Node *curr = head->next;
    while (curr!=NULL){
        if (!(head->data&1) && (curr->data&1)){
            int temp = head->data;
            head->data = curr->data;
            curr->data = temp;
        }
        if (head->data&1){
            head = head->next;
        }
        curr = curr->next;
    }
}
// Another way to arrange ll even after odd without swapping the data
// this is more better as it's actually changing the node, instead of just swapping the data.
Node* evenAfodd(Node *head){
    if (head==NULL || head->next==NULL) return head;
    Node *ohead=NULL, *otail, *ehead=NULL, *etail;
    while (head!=NULL){
        if (head->data&1){
            if (ohead==NULL) ohead=head;
            else otail->next=head;
            otail = head;
        }else{
            if (ehead==NULL) ehead=head;
            else etail->next = head;
            etail = head;
        }
        head = head->next;
    }
    if (ohead==NULL) return ehead;
    if (ehead!=NULL){
        otail->next = ehead;
        etail->next = NULL;
    }
    return ohead;
}

// Delete alternative nodes of a given linked list
void delAlternativeNodes(Node *head){
    Node *n = head->next;
    while (n!=NULL && n->next!=NULL){
        head->next = n->next;
        head = n->next;
        delete n;
        n = head->next;
    }
    if (head->next!=NULL && n->next==NULL){
        head->next = NULL;
        delete n;
    }
}

// Function to swap the linked list
Node* swapNode(Node *head, int i, int j){
    Node *iprev, *jprev, *jnxt;
    Node *temp=head, *iNode=head, *jNode=NULL;
    if (i>j) swap(i, j);
    int curr = 0;
    while (jNode==NULL){
        if (i!=0 && curr == i-1){
            iprev = temp;
            iNode = iprev->next;
        }
        else if (curr == j-1){
            jprev = temp;
            jNode = jprev->next;
            jnxt = jNode->next;
        }
        temp = temp->next;
        curr++;
    }
    if (i!=0) iprev->next = jNode;
    if (i==j-1) jNode->next = iNode;
    else{
        jNode->next = iNode->next;
        jprev->next = iNode;
    }
    iNode->next = jnxt;
    if (i==0) return jNode;
    return head;
}


// Sort the linked list using bubble sort
Node* bubbleSort(Node *head){
    Node *curr = head, *last=NULL;
    while (curr->next!=NULL){
        Node *prev=NULL, *temp=head, *nxt=head->next;
        while (temp->next!=NULL && temp->next!=last){
            if ((temp->data)>(nxt->data)){
                if (prev==NULL){
                    head=nxt;
                    curr = head;
                }
                else prev->next=nxt;
                temp->next = nxt->next;
                nxt->next = temp;
                prev = nxt;
                nxt = temp->next;
            }else{
                prev = temp;
                temp = nxt;
                nxt = nxt->next;
            }
        }
        last = temp;
        curr = curr->next;
    }
    return head;
}


// reverse the linked list at each kth index and connect them all.
void reverse(Node *head){
    if (head->next==NULL){
        return;
    }
    reverse(head->next);
    head->next->next = head;
    head->next = NULL;
}
Node* kreverse(Node *head, int k){
    Node *mHead=NULL, *curr=head, *nHead=head;
    int i=1, j=1;
    while (curr!=NULL){
        if (i==k*j || curr->next==NULL){
            if (curr->next==NULL){
                reverse(nHead);
                head->next = curr;
                curr = NULL;
            }else{
            Node *temp = curr->next;
            curr->next = NULL;
            reverse(nHead);
            if (mHead==NULL){
                mHead = curr;
            }
            if (i>=2*k){
                head->next = curr;
                head = nHead; 
            }
            nHead = temp;
            curr = temp;
            j++;
            }
        }
        else curr = curr->next;
        i++;
    }
    return mHead;
}


// Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
void helper(Node *head){
    if (head->next==NULL){
        if (head->data==9) head->data=0;
        else head->data++;
        return;
    }
    Node *temp = head->next;
    int nxt = temp->data;
    helper(temp);
    if (temp->data==0 && nxt==9){
        if (head->data==9) head->data=0;
        else head->data++;
    }
}
Node* incrementLL(Node *head){
    helper(head);
    if (head->data) return head;
    Node *newNode = new Node(1);
    newNode->next = head;
    return newNode;
}


int main(){

    Node *head = takeInput();
    printLL(head);

    // head = swapNode(head, 4, 0);
    
    // head = bubbleSort(head);

    head = kreverse(head, 4);
    printLL(head);

    return 0;
}