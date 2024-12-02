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

void IntBinaryTree::destroySubTree(TreeNode* nodePtr) {
    if (nodePtr) {
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

bool IntBinaryTree::searchNode(int num) {
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

int main() {
    

    return 0;
}
