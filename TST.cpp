// TST.cpp
#include "TST.h"

#include <iostream>

// Constructor
TST::TST() : root(nullptr)
{
    // do nothing
}

// Destructor
TST::~TST()
{
    // TO IMPLEMENT: Clear memory
}

// Make a new node with key and return it
Node* TST::createNode(std::string key)
{
    Node* n = new Node;
    n->left.key = key;
    n->left.count = 1;
    return n;
}

// Insert key
Node* TST::insert(std::string key)
{
    // If no root, then make a root node with the key
    if (this->root == nullptr)
    {
        Node* n = new Node;
        this->root = createNode(key);
        return n;
    }

    // Start at root, ternary search to find insertion position
    Node* n = this->root;
    while (true)
    {
        // If left is key, then increment its count
        if (n->left.key == key)
        {
            n->left.count++;
            return n;
        }

        // Else if right is key, then increment its count
        else if (n->right.key == key)
        {
            n->right.count++;
            return n;
        }

        // Else if right is empty, insert into this node
        else if (n->right.key == "" && n->right.count == 0)
        {
            // Assume if right is empty, then there are no children
            
            // Set right key and count
            n->right.key = key;
            n->right.count = 1;
            return n;

            // If the left key is greater than the key, then swap left and right
            if (n->left.key > key)
            {
                // Swap left and right keys and counts
                std::swap(n->left.key, n->right.key);
                std::swap(n->left.count, n->right.count);
            }
        }

        // Else, determine whether to traverse to left, middle, or right child
        else
        {
            // If key is less than left, then traverse left child
            if (key < n->left.key)
            {
                // If the left child is null, insert a new node with key
                if (n->leftChild == nullptr)
                {
                    n->leftChild = createNode(key);
                    return n;
                }

                // Else
                n = n->leftChild;
            }

            // Else if key is less than right, then traverse middle child
            else if (key < n->right.key)
            {
                // If the mid child is null, insert a new node with key
                if (n->midChild == nullptr)
                {
                    n->midChild = createNode(key);
                    return n;
                }

                // Else
                n = n->midChild;
            }

            // Else, traverse right child
            else
            {
                // If the right child is null, insert a new node with key
                if (n->rightChild == nullptr)
                {
                    n->rightChild = createNode(key);
                    return n;
                }

                // Else
                n = n->rightChild;
            }
        }
    }
}

// Prints all keys in-order
void TST::inOrder()
{
    inOrderRecurs(this->root);
}

// Prints all keys in-order with root node n
void TST::inOrderRecurs(Node* n)
{
    if (n == nullptr)
    {
        return;
    }
    
    else
    {
        // Print left subtree
        inOrderRecurs(n->leftChild);

        // Print left key and count
        std::string const& left = n->left.key + ", " + std::to_string(n->left.count);
        std::cout << left << std::endl;

        // Print middle subtree
        inOrderRecurs(n->midChild);

        // Print right key and count
        std::string const& right = n->right.key + ", " + std::to_string(n->right.count);
        std::cout << right << std::endl;

        // Print right subtree
        inOrderRecurs(n->rightChild);
    }
}

// Prints all keys pre-order
void TST::preOrder()
{
    
}