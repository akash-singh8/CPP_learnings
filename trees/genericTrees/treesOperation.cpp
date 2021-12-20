#include "treeNode.h"

// Check if given integer x is present in a tree or not
bool isNodePresent(treeNode<int> *root, int target){
    if (root->data == target){
        return true;
    }
    bool isPresent = false;
    for (int i=0; i<root->children.size(); i++){
        isPresent = isNodePresent(root->children[i], target);
        if (isPresent) break;
    }
    return isPresent;
}

// Print all the nodes present at depth d
void printNodesAtD(treeNode<int> *root, int depth){
    if (depth == 1){
        cout<<root->data<<", ";
        return;
    }
    for (int i=0; i<root->children.size(); i++){
        printNodesAtD(root->children[i], depth-1);
    }
}

// Count the number of leave nodes - iteratively
int countLeafNodes(treeNode<int> *root){
    queue<treeNode<int> *> que;
    que.push(root);
    int leafNodes = 0;
    while (!que.empty()){
        bool isLeaf = 1;
        for (int i=0; i<root->children.size(); i++){
            isLeaf = false;
            que.push(root->children[i]);
        }
        if (isLeaf) leafNodes++;
        que.pop();
        root = que.front();
    }
    return leafNodes;
}

// Count the number of leaf nodes - recursively
int countLeafNodesR(treeNode<int> *root){
    if (root->children.size()==0){
        return 1;
    }
    int leaf = 0;
    for (int i=0; i<root->children.size(); i++){
        leaf += countLeafNodes(root->children[i]);
    }
    return leaf;
}


// Find the node with maximum child sum 
void maxChildSumNOde(treeNode<int> *root){
    queue<treeNode<int> *> que;
    que.push(root);
    int node, maxSum = 0;
    while (!que.empty()){
        int currSum = root->data;
        for (int i=0; i<root->children.size(); i++){
            currSum += root->children[i]->data;
            que.push(root->children[i]);
        }
        if (maxSum<currSum){
            maxSum = currSum;
            node = root->data;
        }
        que.pop();
        root = que.front();
    }
    cout<<"Maximum children sum is : "<<maxSum<<" of parent node : "<<node<<endl;
}


// Given an integer n, find a node with value just less than n or just lesser than n
int nextSmallNode(treeNode<int> *root, int n){
    queue<treeNode<int> *> que;
    que.push(root);
    int nextL = -100000;
    bool isPresent = false;
    while (!que.empty()){
        if (root->data<n && nextL<root->data){
            isPresent = true;
            nextL = root->data;
        }
        for (int i=0; i<root->children.size(); i++){
            que.push(root->children[i]);
        }
        que.pop();
        root = que.front();
    }
    if (!isPresent) return -1;
    return nextL;
}


// Find second largest in trees
int secondLargest(treeNode<int> *root){
    int maxN = largestNode(root);
    return nextSmallNode(root, maxN);
}


// replace the data of node with it's current depth
void replaceDepth(treeNode<int> *root, int currD=0){
    root->data = currD;
    for (int i=0; i<root->children.size(); i++){
        replaceDepth(root->children[i], currD+1);
    }
}


int main(){
    treeNode<int> *root = inputTreeLevelWise();
    printTreeLevelWise(root);

    // printNodesAtD(root, 3);
    // cout<<"No. of Leaf Nodes : "<<countLeafNodes(root)<<endl;
    // cout<<"No. of Leaf Nodes : "<<countLeafNodesR(root)<<endl;

    // cout<<"Preorder traversal : ";
    // preorder(root);

    // cout<<"\nPostorder traversal : ";
    // postorder(root);

    // cout<<"Is node present : "<<isNodePresent(root, 40)<<endl;

    // maxChildSumNOde(root);

    // cout<<"Next Smallests : "<<nextSmallNode(root, 4);

    // cout<<"Second Largest Node : "<<secondLargest(root)<<endl
    replaceDepth(root);
    printTreeLevelWise(root);


    return 0;
}