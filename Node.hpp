//
//  Node.hpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Contact.hpp"

using namespace std;

class Node
{
public:
    Node
    (const Contact& data);
    void     setLeft
    (Node* newLeft);
    void     setRight
    (Node* newRight);
    Node*    getLeft
    (void) const;
    Node*    getRight
    (void) const;
    void     write
    (ostream& outfile) const;
    bool operator < (const Node& op2) const;
    
private:
    Contact  info;
    Node*    left  = nullptr;
    Node*    right = nullptr;
};
ostream& operator <<
(ostream& outfile, const Node& n);

#endif /* Node_hpp */
