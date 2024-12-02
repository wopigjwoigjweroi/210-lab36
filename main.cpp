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

void IntBinaryTree::remove(const string &str) {
    
   deleteNode(str, root);
    
}

void IntBinaryTree::deleteNode(const string &str, TreeNode *&nodePtr) {
    
   if (str < nodePtr->value)
      deleteNode(str, nodePtr->left);
       
   else if (str > nodePtr->value)
      deleteNode(str, nodePtr->right);
       
   else
      makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
 
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
       
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
       
      nodePtr = nodePtr->left;  
       
      delete tempNodePtr;
   } else if (!nodePtr->left) {
       
      tempNodePtr = nodePtr;
       
      nodePtr = nodePtr->right;  
      delete tempNodePtr;
   }
   
   else {

      tempNodePtr = nodePtr->right;
     
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
    
      tempNodePtr->left = nodePtr->left;
       
      tempNodePtr = nodePtr;
     
      nodePtr = nodePtr->right;
       
      delete tempNodePtr;
   }
}

int main() {
    

    return 0;
}
