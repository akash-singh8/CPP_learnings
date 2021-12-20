#include "../binaryTrees/input&Print.h"
#include<algorithm>

// Duplicates each node in binary tree and insert it to left subtree
void duplicateBT(binaryNode<int> *root){
    if (root == NULL) return;

    duplicateBT(root->left);
    duplicateBT(root->right);

    binaryNode<int> *temp = new binaryNode<int>(root->data);
    temp->left = root->left;
    root->left = temp;
}


// Given a binary tree & an integer n, print all pair of nodes who's sum is equal to n
// Time Complexity : O(n2),   Space Complexity : O(n);
void storeTree(binaryNode<int> *root, vector<int> &vec){
    if (root == NULL) return;
    storeTree(root->left, vec);
    vec.push_back(root->data);
    storeTree(root->right, vec);
}
void pairSum_NodesOfN(binaryNode<int> *root, int n){
    vector<int> vec;
    storeTree(root, vec);
    for (int i=0; i<vec.size(); i++){
        for (int j=i+1; j<vec.size(); j++){
            if (vec[i]+vec[j]==n){
                cout<<min(vec[i], vec[j])<<" ";
                cout<<max(vec[i], vec[j])<<endl;
                break;
            }
        }
    }
}
// Another way to do the above que in O(nlogn) is to sort the array/vector and then use binary search to find corresponding pair
// Or instead of using binary search lets use double pointer method which will be more efficient
void pairSumNodesOfN(binaryNode<int> *root, int n){
    vector<int> vec;
    storeTree(root, vec);
    sort(vec.begin(), vec.end());
    int i = 0, j = vec.size()-1;
    while (i < j){
        int currSum = vec[i]+vec[j];
        if (currSum == n){
            cout<<vec[i]<<" "<<vec[j]<<endl;
            i++;
            j--;
        }
        else{
            if (currSum > n) j--;
            else i++;
        }
    }
}


/* Given a Binary tree and two node's data, find Least Common Ancestor(LCA) of given nodes, Ancestor of a node in Binary tree is a node 
    that is at upper level of given node, or all the nodes present between the path of given node to root including root are the ancestors 
    of given node, and the Least common ancestor of two nodes are the common ancestor in both nodes which are present at lowest depth 
    in binary tree.
 
 One way to find LCA is to find and store the root to given node path of both in array and just find the least common in them */
bool rootToNodePath(binaryNode<int> *root, int k, vector<int> &vec){
    if (root == NULL) return false;

    if (root->data == k){
        vec.push_back(root->data);
        return true;
    }
    bool left = rootToNodePath(root->left, k, vec);
    if (left){
        vec.push_back(root->data);
        return true;
    }
    bool right = rootToNodePath(root->right, k, vec);
    if (right){
        vec.push_back(root->data);
    }
    return right;
}
int leastCommonAncestor(binaryNode<int> *root, int n1, int n2){
    vector<int> path1, path2;
    bool fst = rootToNodePath(root, n1, path1);
    bool sec = rootToNodePath(root, n2, path2);
    if (fst && sec){
        for (int i=0; i<path1.size(); i++){
            for (int j=0; j<path2.size(); j++){
                if (path1[i] == path2[j]) return path1[i];
            }
        }
    }
    if (fst == false){
        if (sec == false) return -1;
        return n2;
    }
    return n1;
}

// Another way to find Least commoon ancestor, using recursion only, T.C = O(n)  S.C = O(n)
binaryNode<int> *LeastCommonAncestor(binaryNode<int> *root, int p, int q){
    if (root == NULL) return NULL;

    if (root->data == p || root->data == q) return root;

    binaryNode<int> *left = LeastCommonAncestor(root->left, p, q);
    binaryNode<int> *right = LeastCommonAncestor(root->right, p, q);

    if (left && right) return root;
    
    if (left == NULL){
        if (right != NULL) return right;
        return NULL;
    }
    return left;
}


// Find the Lowest Common Ancestor in Binary Search Tree
binaryNode<int> *leastCommonAncestorBST(binaryNode<int> *root, int p, int q){
    if (root == NULL) return NULL;

    if (p < root->data && q < root->data){
        return leastCommonAncestorBST(root->left, p, q);
    }
    if (p > root->data && q > root->data){
        return leastCommonAncestorBST(root->right, p, q);
    }
    return root;
}


// Given a BST, replace each node's data with the sum of all nodes which are greater than or equal to it.
int replaceNodeData(binaryNode<int> *root, int sum=0){
    if (root == NULL) return 0;

    int right = replaceNodeData(root->right, sum);
    root->data += max(right, sum);
    int left = replaceNodeData(root->left, root->data);

    return max(root->data, left);
}


// Given a Binary Tree & an integer k, print all root-leaf node paths which sums equal to k
void sumK_rootLeaf(binaryNode<int> *root, int k, string str = ""){
    if (root == NULL) return;

    str += root->data;
    k -= root->data;
    sumK_rootLeaf(root->left, k, str);
    sumK_rootLeaf(root->right, k, str);
    if (k == 0 && root->left == NULL && root->right == NULL){
        for (int i=0; i<str.length(); i++){
            int temp = str[i];
            cout<<temp<<" ";
        }
        cout<<endl;
    }
}


// Given a Binary Search Tree and an integer s, pair of nodes in BST which sums to s;
void printPairSumBST(binaryNode<int>* root, int s){
    if (root == NULL) return;
    vector<int> vec;
    storeTree(root, vec);
    int i=0, j=vec.size()-1;
    while (i < j){
        int currSum = vec[i] + vec[j];
        if (currSum == s){
            cout<<vec[i]<<" "<<vec[j]<<endl;
            i++;
            j--;
        }
        else{
            if (currSum > s) j--;
            else i++;
        }
    }
}


// Given a binary tree, find the largest BST in it and return the height of that BST
int height(binaryNode<int> *root){
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right)+1;
}
bool checkIfBST(binaryNode<int> *root, int s = INT_MIN, int e = INT_MAX){
    if (root == NULL){
        return true;
    }
    if (root->data < s || root->data > e){
        return false;
    }
    bool left = checkIfBST(root->left, s, root->data-1);
    if (!left) return false;
    bool right = checkIfBST(root->right, root->data, e);

    return right;
}
int largestBST(binaryNode<int> *root){
    if (root == NULL) return 0;
    if (checkIfBST(root) == true) return height(root);

    int left = largestBST(root->left);
    int right = largestBST(root->right);

    return max(left, right);
}

/* T.C of above solution is O(n*h) which is not good, as we're traversing again again one to check if the current node tree is 
    BST or not and again then we are calling recursion of left subtree, so a better way is to return it in a class consists of 
    isBST and height, and for BST class it's imortant to know the left max and right min, so the class should also consists of 
    max and min.      */
class group{
    public:
        int maxN, minN, height;
        bool isBST;
};
group maximumBST(binaryNode<int> *root){
    if (root == NULL){
        group temp;
        temp.maxN = INT_MIN;
        temp.minN = INT_MAX;
        temp.height = 0;
        temp.isBST = true;
        return temp;
    }
    group left = maximumBST(root->left);
    group right = maximumBST(root->right);

    group temp;
    int curr = root->data;
    temp.maxN = max(max(left.maxN, right.maxN), curr);
    temp.minN = min(min(left.minN, right.minN), curr);
    if (left.maxN >= curr || right.minN < curr) temp.isBST = false;
    else temp.isBST = left.isBST && right.isBST;

    if (temp.isBST) temp.height = max(left.height, right.height)+1;
    else temp.height = max(left.height, right.height);
    
    return temp;
}

/* Given a Binary tree, a Node n and an integer k, print all the nodes which is at distance k from node n
void printNodeAtDepth(binaryNode<int> *root, int k){
    
}
int nodeAtDistance(binaryNode<int> *root, int n, int k, binaryNode<int> *curr=NULL){
    if (curr == NULL) return -1;

    if (curr->data == n){
        printNodeAtDepth(curr, k);
        return 0;
    }

    int left = nodeAtDistance(root, n, k, curr->left);
    if (left+1 == k){
        cout<<root->data<<" ";
        return 0;
    }
    if (left){
        printNodeAtDepth(root->right, k-left-2);
        return 0;
    }
    int right = 
} */

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1


int main(){

    binaryNode<int> *root = inputBTLevelWise();
    printBTlevelWise(root);
    
    // duplicateBT(root);
    // printBTlevelWise(root);

    // pairSumNodesOfN(root, 15);

    // cout<<"Least Common Ancestor : "<<LeastCommonAncestor(root, 2, 10)->data<<endl;

    // replaceNodeData(root);
    // printBTlevelWise(root);
    // sumK_rootLeaf(root, 13);

    // cout<<"Largest BST's height : "<<largestBST(root)<<endl;

    group ans = maximumBST(root);
    cout<<"Maximum Number : "<<ans.maxN<<endl;
    cout<<"Minimum Number : "<<ans.minN<<endl;
    cout<<"Is BST : "<<ans.isBST<<endl;
    cout<<"Maximum BST Height : "<<ans.height<<endl;

    // printPairSumBST(root, 9);
    
    deleteBinaryTree(root);

    return 0;
}