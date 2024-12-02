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

        interface(); 
        cin >> select; 

        switch(select) {

            case 1: 
                cout << "Enter string to insert: "; 
                cin >> val; 
                tree.insertNode(val); 
                break; 

            case 2: 
                cout << "Enter string to search: "; 
                cin >> val; 
                if (tree.searchNode(val)) {

                    cout << val << " found.\n"; 
                } else {

                    cout << val << " not found.\n"; 
                }
                break; 

            case 3: 
                cout << "Enter a string to remove: "; 
                cin >> val; 
                tree.remove(val); 
                break; 

            case 4: 
                cout << "BST Contents In-Order: \n"; 
                tree.displayInOrder();
                break; 

            case 5: 
                cout << "Quitting..."; 
                break;

            default:
                cout << "Invalid.\n"; 
        }
    } while (select !=5); 

    return 0;
}
