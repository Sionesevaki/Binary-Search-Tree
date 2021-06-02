//
//  BinarySearchTree.cpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include "BinarySearchTree.hpp"

void BinarySearchTree::addRecursively(const Contact& newEntry)
{
    Node* n = new Node(newEntry);
    addRecursively(root, n);
}

void BinarySearchTree::addIteratively(const Contact& newEntry)
{
    if(root)
    {
        Node* newCon = new Node(newEntry);
        Node* n = root;
        
        while(n)
        {
            if(*newCon <(*n))
            {
                if(n->getLeft())
                {
                    n = n->getLeft();
                }
                else
                {
                    n->setLeft(newCon);
                    return;;
                }
            }
            else 
            {
                if(n->getRight())
                {
                    n = n->getRight();
                }
                else
                {
                    n->setRight(newCon);
                    return;
                }
            }
        }
    }
    else
    {
        Node* n = new Node(newEntry);
        root = n;
    }
    
}

void BinarySearchTree::writeRecursively(ostream& outfile) const
{
    writeRecursively(outfile, root);
    
    return;
}

void BinarySearchTree::writeIteratively(ostream& outfile) const
{
    if(root)
    {
        stack<Node*> nodes;
        Node *current = root;
        while (!nodes.empty() || current)
        {
            if(current)
            {
                nodes.push(current);
                current = current->getLeft();
            }
            else
            {
                current = nodes.top();
                nodes.pop();
                current->write(outfile);
                current = current->getRight();
            }
        }
    }
    else
    {
        outfile << "Iterative Listing Failed: Empty Tree" << endl;
        return;
    }
}

void BinarySearchTree::eraseRecursively(void)
{
    eraseRecursively(root);
}

/////////////////////PRIVATE FUNCTIONS/////////////////////////////

void BinarySearchTree::eraseRecursively(Node* currentRoot)
{
    if (!currentRoot)
    {
        return;
    }
    
    eraseRecursively(currentRoot->getLeft());
    eraseRecursively(currentRoot->getRight());
    
    free(currentRoot);
}

void BinarySearchTree::addRecursively(Node* currentRoot, Node* newNode)
{
    if(!currentRoot)
    {
        currentRoot = newNode;
    }
    else
    {
        if(*newNode <(*currentRoot))
        {
            addRecursively(currentRoot->getLeft(), newNode);
        }
        else
        {
            addRecursively(currentRoot->getRight(), newNode);
        }
    }
    
    return;
}

void BinarySearchTree::writeRecursively(ostream& outfile, Node* currentRoot) const
{
    if(currentRoot)
    {
        writeRecursively(outfile, currentRoot->getLeft());
        currentRoot->write(outfile);
        writeRecursively(outfile, currentRoot->getRight());
    }
    else
        return;
}

