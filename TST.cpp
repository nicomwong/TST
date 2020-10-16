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

// Prints out 'key found, count = x' if key is found; else, 'key not found'
void TST::lookup(std::string key)
{
    Node* n = find(key);
    if (n == nullptr)
    {
        // Print 'key not found'
        std::cout << key << " not found" << std::endl;
    }

    else
    {
        // Determine which key was the one found
        int count = n->left.key == key ? n->left.count : n->right.count;

        // Print 'key found, count = x'
        std::cout << key << " found, count = " << count << std::endl;
    }
}

// Prints out 'key inserted, new count = x' once key is inserted
void TST::insertPrint(std::string key)
{
    Node* n = insert(key);
    if (n == nullptr)
    {
        // Print error message that insert() shouldn't return nullptr
        std::cerr << "----ERROR: insert(\"" << key << "\") returned nullptr" << std::endl;
    }

    else
    {
        // Determine which key was the one inserted
        int count = n->left.key == key ? n->left.count : n->right.count;

        // Print 'key inserted, new count = x'
        std::cout << key << " inserted, new count = " << count << std::endl;
    }
    
}

// Finds the node with key
Node* TST::find(std::string key)
{
    // Start at the root node
    Node* n = this->root;

    // Traverse down the tree, moving left, mid, or right depending on key values until it is found (or not found)
    while (n != nullptr)
    {
        // If key is in this node, return the node
        if (n->left.key == key || n->right.key == key)
        {
            return n;
        }

        // Else, determine which child to traverse
        else
        {
            // If key is less than left key, then go to left child
            if (key < n->left.key)
            {
                n = n->leftChild;
            }

            // Else if key is less than right key, then go to middle child
            else if (key < n->right.key)
            {
                n = n->midChild;
            }

            // Else, go to right child
            else
            {
                n = n->rightChild;
            }
        }
    }

    // This line is reached once n == nullptr
    // Means that there are no nodes left to search
    return nullptr;
}

// Insert key
Node* TST::insert(std::string key)
{
    // If no root, then make a root node with the key
    if (this->root == nullptr)
    {
        this->root = createNode(key);
        return this->root;
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

            // If the left key is greater than the key, then swap left and right
            if (n->left.key > key)
            {
                // Swap left and right keys and counts
                std::swap(n->left.key, n->right.key);
                std::swap(n->left.count, n->right.count);
            }

            return n;
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

// Prints all keys from m to n, double inclusive, in-order
void TST::rangeSearch(std::string low, std::string high)
{
    rangeSearchRecurs(low, high, this->root);
}

// Prints all keys in-order
void TST::inOrder()
{
    inOrderRecurs(this->root);
}

// Prints all keys pre-order
void TST::preOrder()
{
    preOrderRecurs(this->root);
}

// Prints all keys post-order
void TST::postOrder()
{
    postOrderRecurs(this->root);
}

// Make a new node with key as left and return it
Node* TST::createNode(std::string key)
{
    Node* n = new Node;
    n->left.key = key;
    n->left.count = 1;
    return n;
}

// Prints all keys from lo to hi, double inclusive, in-order with root node n
void TST::rangeSearchRecurs(std::string const& lo, std::string const& hi, Node* n)
{
    if (n == nullptr)
    {
        return;
    }

    else
    {
        // Print the left subtree
        rangeSearchRecurs(lo, hi, n->leftChild);

        // If the left key is in the range, then print it
        if (lo <= n->left.key && n->left.key <= hi)
        {
            std::cout << n->left.key << std::endl;
        }

        // Print the middle subtree
        rangeSearchRecurs(lo, hi, n->midChild);

        // If the right key is in the range, then print it
        if (lo <= n->right.key && n->right.key <= hi)
        {
            std::cout << n->right.key << std::endl;
        }

        // Print the right subtree
        rangeSearchRecurs(lo, hi, n->rightChild);
    }
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

// Prints all keys pre-order with root n
void TST::preOrderRecurs(Node* n)
{
    if (n == nullptr)
    {
        return;
    }

    else
    {
        // Print left key and count
        std::string const& left = n->left.key + ", " + std::to_string(n->left.count);
        std::cout << left << std::endl;
        
        // Print right key and count
        std::string const& right = n->right.key + ", " + std::to_string(n->right.count);
        std::cout << right << std::endl;

        // Print left subtree
        preOrderRecurs(n->leftChild);

        // Print middle subtree
        preOrderRecurs(n->midChild);

        // Print right subtree
        preOrderRecurs(n->rightChild);
    }
    
}

// Prints all keys post-order with root n
void TST::postOrderRecurs(Node* n)
{
    if (n == nullptr)
    {
        return;
    }

    else
    {
        // Print left subtree
        postOrderRecurs(n->leftChild);

        // Print middle subtree
        postOrderRecurs(n->midChild);

        // Print right subtree
        postOrderRecurs(n->rightChild);

        // Print left key and count
        std::string const& left = n->left.key + ", " + std::to_string(n->left.count);
        std::cout << left << std::endl;
        
        // Print right key and count
        std::string const& right = n->right.key + ", " + std::to_string(n->right.count);
        std::cout << right << std::endl;
    }
}