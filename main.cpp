#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
    if (!nodePtr)
        nodePtr = newNode; 
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); 
    else
        insert(nodePtr->right, newNode); 
}

void IntBinaryTree::insertNode(const string& str) {
    TreeNode* newNode = new TreeNode;
    newNode->value = str;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}

int main() {
    

    return 0;
}
