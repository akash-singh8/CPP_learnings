#include"input&Print.h"

// Count number of nodes present in binary tree
int countNodes(binaryNode<int> *root){
    if (root == NULL){
        return 0;
    }
    int ans = 1;
    ans += countNodes(root->left) + countNodes(root->right);
    return ans;
}


// Check if the given node is present in a binary tree or not
bool isNodePresent(binaryNode<int> *root, int target){
    if (root == NULL){
        return false;
    }
    if (root->data == target){
        return true;
    }
    return isNodePresent(root->left, target) || isNodePresent(root->right, target);
}


// Sum of Nodes present in binary tree
int nodesSum(binaryNode<int> *root){
    if (root == NULL){
        return 0;
    }
    int leftSum = nodesSum(root->left);
    int rightSum = nodesSum(root->right);
    return leftSum + rightSum + root->data;
}

// find height of the binary tree
int binaryTreeHeight(binaryNode<int> *root){
    if (root == NULL){
        return 0;
    }
    int leftHeight = binaryTreeHeight(root->left);
    int rightHeight = binaryTreeHeight(root->right);
    
    return max(leftHeight, rightHeight)+1;
}


// Mirror the given binary tree
void mirrorBinaryTree(binaryNode<int> *root){
    if (root == NULL || root->left == NULL && root->right == NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    swap(root->left, root->right);
}


/* Binary Tree Traversal :
    1. Level-Wise : that we've already done using the queue data structure
    2. Preorder Traversal : root -> left -> right, first we access the node then left child & then right child.
    3. Postorder Traversal : left -> right -> root, 1st we access the left child then right child & then the node.
    4. Inorder Traversal : left -> root -> right 
*/
void preorder(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


/* Application of Preorder, Postorder & Inorder : 
1. Given Preorder & Inorder traversal of a binary tree, build the binary trees using given data & return root, by using only one of them
    we can't print the exact tree that's why two different traversal has been given */
binaryNode<int> *buildTreeHelper(int preorder[], int inorder[], int pS, int pE, int inS, int inE){
    if (pS>pE || inS>inE){
        return NULL;
    }
    int rootIndIn = 0;
    for (; preorder[pS]!=inorder[rootIndIn]; rootIndIn++){}
    int lInS=inS, lInE=rootIndIn-1;
    int rInS=rootIndIn+1, rInE=inE;
    int lPreS=pS+1, lPreE=rootIndIn-inS+pS;
    int rPreS=rootIndIn+pS+1, rPreE=pE;

    binaryNode<int> *root = new binaryNode<int>(preorder[pS]);
    root->left = buildTreeHelper(preorder, inorder, lPreS, lPreE, lInS, lInE);
    root->right = buildTreeHelper(preorder, inorder, rPreS, rPreE, rInS, rInE);

    return root;
}
binaryNode<int> *buildBinaryTree(int preorder[], int inorder[], int size){
    return buildTreeHelper(preorder, inorder, 0, size-1, 0, size-1);
}


// Given Postorder & Inorder traversal, build a binary tree using given data
binaryNode<int> *buildBTreeHelper(int postorder[], int inorder[], int posS, int posE, int inS, int inE){
    if (posS>posE || inS>inE){
        return NULL;
    }
    int rootIndIn = 0;
    for (; postorder[posE]!=inorder[rootIndIn]; rootIndIn++){}

    int lInS = inS, lInE = rootIndIn-1;
    int lPoS = posS, lPosE = rootIndIn-1;
    int rInS = rootIndIn+1, rInE = inE;
    int rPosS = rootIndIn, rPosE = posE-1;

    binaryNode<int> *root = new binaryNode<int>(postorder[posE]);
    root->left = buildBTreeHelper(postorder, inorder, lPoS, lPosE, lInS, lInE);
    root->right = buildBTreeHelper(postorder, inorder, rPosS, rPosE, rInS, rInE);
    
    return root;
}
binaryNode<int> *buildBTree(int postorder[], int inorder[], int size){
    return buildBTreeHelper(postorder, inorder, 0, size-1, 0, size-1);
}

// Check if a binary trees is balanced or not, it's balanced if depth of it's left & right subtrees of every node differ by at max 1
bool isBinaryTreeBalanced(binaryNode<int> *root){
    if (root == NULL){
        return true;
    }
    int leftHeight = binaryTreeHeight(root->left);
    int rightHeight = binaryTreeHeight(root->right);
    if (abs(leftHeight-rightHeight)>1){
        return false;
    }
    return isBinaryTreeBalanced(root->left) && isBinaryTreeBalanced(root->right);
}


// Remove all leaf nodes from a given Binary Tree
void removeLeafNodes(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    if (root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
        delete root->left;
        root->left = NULL;
    }
    if (root->right!=NULL && root->right->left==NULL && root->right->right==NULL){
        delete root->right;
        root->right = NULL;
    }
    removeLeafNodes(root->left);
    removeLeafNodes(root->right);
}


// Find the diameter of binary tree  Time Complexity : O(n*h) n -> no. of nodes, h-> height of binary tree
int binaryTreeDiameter(binaryNode<int> *root){
    if (root == NULL){
        return 0;
    }
    int currD = binaryTreeHeight(root->left) + binaryTreeHeight(root->right);
    int leftD = binaryTreeDiameter(root->left);
    int rightD = binaryTreeDiameter(root->right);

    return max(max(leftD, rightD), currD);
}


// Find the diameter with better time complexity i.e. O(n)
pair<int, int> diameterHelper(binaryNode<int> *root){
    if (root == NULL){
        pair<int, int> temp;
        temp.first = 0;
        temp.second= 0;
        return temp;
    }
    pair<int, int> left =  diameterHelper(root->left);
    pair<int, int> right =  diameterHelper(root->right);

    pair<int, int> temp;
    temp.first = max(left.first, right.first)+1;
    temp.second = max(max(left.second, right.second), left.first+right.first);

    return temp;
}
int BTdiameter(binaryNode<int> *root){
    return diameterHelper(root).second;
}


// Print all the nodes without any sibling 
void nodeWOsibling(binaryNode<int> *root){
    if (root == NULL){
        return;
    }
    if (root->left!=NULL && root->right==NULL) cout<<root->left->data<<" ";
    if (root->left==NULL && root->right!=NULL) cout<<root->right->data<<" ";
    nodeWOsibling(root->left);
    nodeWOsibling(root->right);
}


// Print the given binary tree in zig-zag order, i.e. print level-1 from left-right & level-2 from right-left....so on
#include<vector>
void zigZagBinaryTree(binaryNode<int> *root){
    queue<binaryNode<int> *> que;
    que.push(root);
    que.push(NULL);
    cout<<root->data<<endl;
    vector<int> vec;
    int curr = 2;
    while (!que.empty()){
        if (root->left != NULL){
            que.push(root->left);
            vec.push_back(root->left->data);
        }
        if (root->right != NULL){
            que.push(root->right);
            vec.push_back(root->right->data);
        }
        que.pop();
        root = que.front();
        if (root == NULL){
            if (curr & 1){
                for (int i=0; i<vec.size(); i++){
                    cout<<vec[i]<<" ";
                }
            }
            else{
                for (int i=vec.size()-1; i>=0; i--){
                    cout<<vec[i]<<" ";
                }
            }
            que.pop();
            if (!que.empty()){
                que.push(NULL);
                vec.clear();
                cout<<endl;
                root = que.front();
                curr++;
            }
        }
    }
}

int main(){

    binaryNode<int> *root = inputBTLevelWise();
    printBTlevelWise(root);

    cout<<"Number of nodes : "<<countNodes(root)<<endl;

    // cout<<"Is Node Present : "<<isNodePresent(root, 4);

    // cout<<"Sum of Nodes : "<<nodesSum(root)<<endl;

    cout<<"Height : "<<binaryTreeHeight(root)<<endl;

    // mirrorBinaryTree(root);
    // printBTlevelWise(root);

    cout<<"Preorder traversal : ";
    preorder(root);

    cout<<"\nPostorder traversal : ";
    postorder(root);

    cout<<"\nInorder traversal : ";
    inorder(root);

    
    cout<<"\nIs Binary Tree Balanced : "<<isBinaryTreeBalanced(root)<<endl;

    // int postorder[5] = {4, 5, 2, 3, 1}, inorder[5] = {4, 2, 5, 1, 3};
    // binaryNode<int> *rN = buildBinaryTree(preorder, inorder, 4);
    // binaryNode<int> *rN = buildBTree(postorder, inorder, 5);
    // printBTlevelWise(rN);
    // deleteBinaryTree(rN);

    // cout<<"Diameter of Binary Tree : "<<binaryTreeDiameter(root)<<endl;
    cout<<"Diameter of Binary Tree : "<<BTdiameter(root)<<endl;

    pair<int, int> maxMin = findMaxMin(root);
    cout<<"Max : "<<maxMin.first<<"  and  Min : "<<maxMin.second<<endl;

    // removeLeafNodes(root);
    // printBTlevelWise(root);

    // nodeWOsibling(root);

    zigZagBinaryTree(root);

    deleteBinaryTree(root);

    return 0;
}