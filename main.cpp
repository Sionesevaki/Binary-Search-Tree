//
//  main.cpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "Node.hpp"
#include "Contact.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

Contact readContact(istream& infile)
{
    Contact newEntry;
    infile >> newEntry.name >> newEntry.phone;
    return newEntry;
}

int main(int argc, const char * argv[])
{
    ifstream infile("bst_data_in.txt");
    if (!infile)
    {
        cout << "Error opening bst_data_in.txt!\n";
        exit (1);
    }
    
    Node n1 {readContact(infile)};
    Node n2 {readContact(infile)};
    
    cout << "test nodes:\n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout <<       endl;
    
    cout << "Press <enter> to continue...\n";
    cin.get();
    BinarySearchTree customerTree;
    infile.clear();   // restore stream state so I/O may proceed
    infile.seekg(0);  // seek "get" to file start (byte #0)
    while (infile.good())
        customerTree.addIteratively(readContact(infile));
    cout << "Recursive Tree Listing of Iterative Additions\n";
    customerTree.writeRecursively(cout);
    
    cout << "Press <enter> to continue...\n";
    cin.get();
    customerTree.eraseRecursively();
    cout << "Recursive Tree Listing After Erase:\n";
    customerTree.writeRecursively(cout);
    cout << "<end of tree output>\n\n";
    
    infile.clear();    // restore stream state so I/O may proceed
    infile.seekg(0);   // seek "get" to file start (byte #0)
    while (infile.good())
        customerTree.addRecursively(readContact(infile));  // recursive add
    cout << "Iterative Listing of Recursive Additions\n";
    customerTree.writeIteratively(cout);
    infile.close();
}
