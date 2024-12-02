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

bool IntBinaryTree::searchNode(const string &str) {
   TreeNode *nodePtr = root;

   while (nodePtr) {
       
      if (nodePtr->value == str)
         return true;
          
      else if (str < nodePtr->value)
         nodePtr = nodePtr->left;
          
      else
         nodePtr = nodePtr->right;
   }
    
   return false;
}

void IntBinaryTree::remove(int num) {
    
   deleteNode(num, root);
    
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
    
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
       
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
       
   else
      makeDeletion(nodePtr);
}

int main() {
    

    return 0;
}
