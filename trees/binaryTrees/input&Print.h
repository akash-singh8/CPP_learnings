#include<iostream>
#include<queue>

using namespace std;

/* Binary tree is based on trees data structure & a special type of tree, in which the parent nodes can't have more than
   two childrens or a tree where every node has max 2 children, In binary tree a node only consists of data and two pointer 
   variables which will be used to store the addresses of it's children unlike in generic tree we don't need to use a vector
   here. */

template <class dT>
class binaryNode{
    public:
        dT data;
        binaryNode<int> *left = NULL, *right = NULL;

        binaryNode(dT data){
            this->data = data;
        }
};


// Function to take input for binary tree
binaryNode<int> *inputBinaryTree(){
    int data;
    cin>>data;
    if (data == -1){
        return NULL;
    }
    binaryNode<int> *root = new binaryNode<int>(data);
    binaryNode<int> *leftChild = inputBinaryTree();
    binaryNode<int> *rightChild = inputBinaryTree();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}


// Printing the binary tree
void printBinaryTree(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    if (root->left != NULL) cout<<"L-"<<root->left->data<<", ";
    if (root->right != NULL) cout<<"R-"<<root->right->data;
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}


// Function to delete the binary tree
void deleteBinaryTree(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}


// Input binary tree level wise
binaryNode<int> *inputBTLevelWise(){
    queue<binaryNode<int> *> que;
    int data;
    cin>>data;
    binaryNode<int> *root = new binaryNode<int>(data);
    binaryNode<int> *curr = root;
    que.push(root);
    while (!que.empty()){
        int left, right;
        cout<<"Enter left and right children of "<<curr->data<<" : ";
        cin>>left>>right;
        if (left != -1){
            binaryNode<int> *leftChild = new binaryNode<int>(left);
            curr->left = leftChild;
            que.push(leftChild);
        }
        if (right != -1){
            binaryNode<int> *rightChild = new binaryNode<int>(right);
            curr->right = rightChild;
            que.push(rightChild);
        }
        que.pop();
        curr = que.front();
    }
    return root;    
}

// Print binary tree level wise
void printBTlevelWise(binaryNode<int> *root){
    queue<binaryNode<int> *> que;
    que.push(root);
    while (!que.empty()){
        cout<<root->data<<" : ";
        if (root->left != NULL){
            cout<<"L-"<<root->left->data<<", ";
            que.push(root->left);
        }
        if (root->right != NULL){
            cout<<"R-"<<root->right->data;
            que.push(root->right);
        }
        cout<<endl;
        que.pop();
        root = que.front();
    }
    cout<<endl;
}

// Return maximum and minimum value of an binary tree
pair<int, int> findMaxMin(binaryNode<int> *root){
    if (root == NULL){
        pair<int, int> p;
        p.first = -10000;
        p.second = 10000;
        return p;
    }
    pair<int, int> left = findMaxMin(root->left);
    pair<int, int> right = findMaxMin(root->right);
    
    pair<int, int> temp;
    temp.first = max(root->data, max(left.first, right.first));
    temp.second = min(root->data, min(left.second, right.second));
    
    return temp;
}