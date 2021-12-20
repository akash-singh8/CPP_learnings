#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/* Implementing a class to create a tree Node, It's similar as the Node we have seen in linked list the only difference is Node of a tree 
   can store address of more than one Node, and The main/first Node in tree is called Root Node and the address stored of others node in a 
   node is called it's childrens and that node is called Parent. Leaf Nodes are those which doesn't have any children or the last node in 
   a tree.        
   So in order to create a tree Node we've to store the data and addresses of it's childrens (for that we'll use an linear data structure)
*/


template <class dT>
class treeNode{
    public:
        dT data;
        vector<treeNode<dT> *> children;

        treeNode(int data){
            this->data = data;
        }
};


template <typename dT>

treeNode<dT> *inputTree(){
    dT data, size;
    cin>>data>>size;
    treeNode<dT> *root = new treeNode<dT>(data);
    for (int i=0; i<size; i++){
        treeNode<dT> *child = inputTree<dT>();
        root->children.push_back(child);
    }
    return root;
}


template <typename dT>
void printTree(treeNode<dT> *root){
    cout<<root->data<<" : ";
    for (int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for (int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}


template <typename dT>

void deleteTree(treeNode<dT> *root){
    for (int i=0; i<root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}


// Taking input level wise using queue
treeNode<int> *inputTreeLevelWise(){
    queue<treeNode<int> *> que;
    int data, size;
    cin>>data;
    treeNode<int> *root = new treeNode<int>(data);
    treeNode<int> *curr = root;
    que.push(root);
    while (!que.empty()){
        cout<<"Enter number of children of "<<curr->data<<" : ";
        cin>>size;
        for (int i=0; i<size; i++){
            int cData;
            cout<<"Enter "<<i<<"th child of "<<curr->data<<" : ";
            cin>>cData;
            treeNode<int> *child = new treeNode<int>(cData);
            curr->children.push_back(child);
            que.push(child);
        }
        que.pop();
        curr = que.front();
    }
    cout<<endl;
    return root;
}


// Program to print the tree level wise
void printTreeLevelWise(treeNode<int> *root){
    queue<treeNode<int> *> que;
    que.push(root);
    while (!que.empty()){
        cout<<root->data<<" : ";
        for (int i=0; i<root->children.size(); i++){
            cout<<root->children[i]->data<<", ";
            que.push(root->children[i]);
        }
        cout<<endl;
        que.pop();
        root = que.front();
    }
}


// Count number of nodes present in tree or find the size of tree - Iteratively T.C : O(N)   S.C : O(N)
int treeSize(treeNode<int> *root){
    queue<treeNode<int> *> que;
    int size=1;
    que.push(root);
    while(!que.empty()){
        for (int i=0; i<root->children.size(); i++){
            que.push(root->children[i]);
            size++;
        }
        que.pop();
        root = que.front();
    }
    return size;
}


// Finding the size of tree Recursively
int treeSizeR(treeNode<int> *root){
    int size=1;
    for (int i=0; i<root->children.size(); i++){
        size += treeSizeR(root->children[i]);
    }
    return size;
}


// Sum of all nodes present in a tree
int sumAllNodes(treeNode<int> *root){
    int sum = root->data;
    for (int i=0; i<root->children.size(); i++){
        sum += sumAllNodes(root->children[i]);
    }
    return sum;
}


// find Node with largest data
int largestNode(treeNode<int> *root){
    queue<treeNode<int> *> que;
    int maxN = root->data;
    que.push(root);
    while (!que.empty()){
        for (int i=0; i<root->children.size(); i++){
            int curr = root->children[i]->data;
            if (maxN < curr) maxN = curr;
            que.push(root->children[i]);
        }
        que.pop();
        root = que.front();
    }
    return maxN;
}


/* Preorder traversal means in which we do first print all the data of one node & then go to other's node, means first we'll print the 
parent node and then print it's childrens by traversing traverse the tree in vertical order, there's another type of traversal known as 
postorder in which we traverse from bottom to up mean first  we'll print all the childrens of a node and then print that node */
void preorder(treeNode<int> *root){
    cout<<root->data<<" ";
    for (int i=0; i<root->children.size(); i++){
        preorder(root->children[i]);
    }
}

void postorder(treeNode<int> *root){
    for (int i=0; i<root->children.size(); i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}