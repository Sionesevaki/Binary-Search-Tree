//
//  Node.cpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include "Node.hpp"

Node::Node(const Contact& data)
{
    info = data;
}

void Node::setLeft(Node* newLeft)
{
    left = newLeft;
}

void Node::setRight(Node* newRight)
{
    right = newRight;
}

Node* Node::getLeft(void) const
{
    return left;
}

Node* Node::getRight(void) const
{
    return right;
}

void Node::write(ostream& outfile) const
{
    info.write(outfile);
}

ostream& operator << (ostream& outfile, const Node& n)
{
    n.write(outfile);
    
    return outfile;
}

bool Node::operator < (const Node& op2) const
{
    if(info.name < op2.info.name)
        return true;
    else
        return false;
}
