#include <iostream>
#include <fstream> 
#include "IntBinaryTree.h"
using namespace std;

void interface() {

    cout << "1. Insert\n";
    cout << "2. Search.\n";
    cout << "3. Delete.\n"; 
    cout << "4. In-Order Display.\n"; 
    cout << "5. Quit.\n"; 

}

int main() {

    IntBinaryTree tree;

    fstream inputFile("codes.txt");

    string str; 

    if (inputFile) {

        while (getline(inputFile, str)) {

            tree.insertNode(str); 
        }

        inputFile.close(); 
    } 

    int select; 

    string val; 

    do {

        

    }

    return 0;
}
