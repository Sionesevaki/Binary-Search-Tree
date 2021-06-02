//
//  BinarySearchTree.hpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Contact.hpp"
#include "Node.hpp"
#include <stack> 

using namespace std;

class BinarySearchTree
{
public:
    BinarySearchTree
    (void)                        = default;
    ~BinarySearchTree(void) {eraseRecursively();};
    void     addRecursively
    (const Contact& newEntry);
    void     addIteratively
    (const Contact& newEntry);
    void     writeRecursively
    (ostream& outfile) const;
    void     writeIteratively
    (ostream& outfile) const;
    void     eraseRecursively
    (void);
    
private:
    // methods
    void     eraseRecursively
    (Node* currentRoot);
    void     addRecursively       // called by public version
    (Node* currentRoot, Node* newNode);
    void     writeRecursively     // called by public version
    (ostream& outfile, Node* currentRoot) const;
    // attributes
    Node*    root = nullptr;      // initially empty tree (null root)
   
    
    // disabled methods
    BinarySearchTree              // copy c-tor
    (const BinarySearchTree&)     = delete;
    BinarySearchTree& operator=   // assignment operator
    (const BinarySearchTree& rhs) = delete;
    
};


#endif /* BinarySearchTree_hpp */
