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
    destroyTree(this->root);
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

// Prints 'key deleted, new count = x' if count > 1; else, 'key deleted'; after deleting
void TST::deletePrint(std::string key)
{
    // Delete key from root then set the new root
    this->root = deleteKey(key, this->root, true);
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

// Destructor helper; deletes memory (post-order) from tree with root n
void TST::destroyTree(Node* n)
{
    if (n == nullptr)
    {
        return;
    }

    else
    {
        // Delete left, mid, and right subtrees
        destroyTree(n->leftChild);
        destroyTree(n->midChild);
        destroyTree(n->rightChild);

        // Delete this node
        delete n;
    }
    
}

// Deletes key from tree with root n and returns the new root
// If the isFirstDelete flag is false, then the whole NodeKey is reset/deleted no matter its count
Node* TST::deleteKey(std::string key, Node* n, bool isFirstDelete)
{
    // If n is null or key is empty, return
    if (n == nullptr || key == "")
    {
        return nullptr;
    }

    // Else if right is empty, then this node has no children
    else if (n->right.key == "" && n->right.count == 0)
    {
        // If left is key, then delete it and possibly delete this node
        if (n->left.key == key)
        {
            // If count > 1 and isFirstDelete is true, then decrement the count
            if (n->left.count > 1 && isFirstDelete == true)
            {
                n->left.count--;
                printKeyDeleted(n->left, false);    // Print that this key was partially deleted
                return n;
            }

            // Else, delete this node and return nullptr as new root
            else
            {
                // If isFirstDelete is true, then print that this key was deleted
                if (isFirstDelete == true)
                {
                    printKeyDeleted(n->left, true); // Print that this key was fully deleted
                }
                
                delete n;
                return nullptr;
            }
        }

        // Else, key is not in the tree so stop and return this node as new root
        else
        {
            return n;
        }
    }

    // Else if left is key
    else if (n->left.key == key)
    {
        bool fullyDeleted = true;   // Tracks whether key was fully deleted for correct printing
        NodeKey deletedKey = n->left; // Tracks the key that is being deleted

        // If count > 1 and isFirstDelete is true, then decrement the count
        if (n->left.count > 1 && isFirstDelete == true)
        {
            n->left.count--;
            deletedKey = n->left;   // Update the deleted key
            fullyDeleted = false;   // Mark that it was not fully deleted
        }

        // Else if left subtree exists,
        else if (n->leftChild != nullptr)
        {
            // Set left to max of left subtree
            n->left = findMax(n->leftChild);

            // Delete the max from the left subtree and set the left child to the new root
            n->leftChild = deleteKey(n->left.key, n->leftChild, false);
        }

        // Else if middle subtree exists,
        else if (n->midChild != nullptr)
        {
            // Set left to min of middle subtree
            n->left = findMin(n->midChild);

            // Delete the min from the middle subtree and set the left child to the new root
            n->midChild = deleteKey(n->left.key, n->midChild, false);
        }

        // Else, fill in from right to left
        else
        {
            // Set the left to the right
            n->left = n->right;

            // Set the right to the min of the right subtree
            n->right = findMin(n->rightChild);

            // Delete the min from the right child and set the right child to the new root
            n->rightChild = deleteKey(n->right.key, n->rightChild, false);
        }

        // If this is the first delete, then print that this key was deleted
        if (isFirstDelete == true)
        {
            printKeyDeleted(deletedKey, fullyDeleted);
        }

        // Return this node as the root
        return n;
    }

    // Else if right is key
    else if (n->right.key == key)
    {
        bool fullyDeleted = true;   // Tracks whether key was fully deleted for correct printing
        NodeKey deletedKey = n->right;  // Tracks the key that is being deleted

        // If count > 1 and isFirstDelete is true, then decrement the count
        if (n->right.count > 1 && isFirstDelete == true)
        {
            n->right.count--;
            deletedKey = n->right;  // Updates deleted key
            fullyDeleted = false;   // Sets fullyDeleted to false
        }

        // Else if middle subtree exists,
        else if (n->midChild != nullptr)
        {
            // Set right to the max of the middle subtree
            n->right = findMax(n->midChild);

            // Delete the max from the middle subtree and set the middle child to the new root
            n->midChild = deleteKey(n->right.key, n->midChild, false);
        }

        // Else if right subtree exists,
        else if (n->rightChild != nullptr)
        {
            // Set right to the min the of right subtree
            n->right = findMin(n->rightChild);

            // Delete the min from the right subtree and set the right child to the new root
            n->rightChild = deleteKey(n->right.key, n->rightChild, false);
        }

        // Else if left subtree exists, fill in from left to right
        else if (n->leftChild != nullptr)
        {
            // Set the right to the left
            n->right = n->left;

            // Set the left to the max of the left subtree
            n->left = findMax(n->leftChild);

            // Delete the max from the left subtree and set the left child to the new root
            n->leftChild = deleteKey(n->left.key, n->leftChild, false);
        }

        // Else, reset/delete the right key
        else
        {
            n->right = NodeKey("", 0);
        }

        // If this is the first delete, then print that this key was deleted
        if (isFirstDelete == true)
        {
            printKeyDeleted(deletedKey, fullyDeleted);
        }

        // Return this node as the root
        return n;
    }

    // Else if key < left key, then delete the key from left subtree
    else if (key < n->left.key)
    {
        // Delete the key from left subtree and set the left child to the new root
        n->leftChild = deleteKey(key, n->leftChild, isFirstDelete);
        return n;
    }

    // Else if key < right key, then delete the key from middle subtree
    else if (key < n->right.key)
    {
        // Delete the key from middle subtree and set the middle child to the new root
        n->midChild = deleteKey(key, n->midChild, isFirstDelete);
        return n;
    }

    // Else, the key can only be in right subtree
    else
    {
        // Delete the key from the right subtree and set the right child to the new root
        n->rightChild = deleteKey(key, n->rightChild, isFirstDelete);
        return n;
    }
}

// If the fullyDeleted flag is true, then prints 'key deleted'; else, prints 'key deleted, new count = x'
void TST::printKeyDeleted(NodeKey const& nk, bool fullyDeleted)
{
    if (fullyDeleted == true)
    {
        std::cout << nk.key << " deleted" << std::endl;
    }

    else
    {
        std::cout << nk.key << " deleted, new count = " << nk.count << std::endl;
    }
}

// Finds the minimum key from tree with root n
NodeKey TST::findMin(Node* n)
{
    // If n is null, then return an empty key
    if (n == nullptr)
    {
        return NodeKey("", 0);
    }
    
    // Else, Traverse left until it is no longer possible
    while (true)
    {
        // If the left subtree exists, then move to the left child
        if (n->leftChild != nullptr)
        {
            n = n->leftChild;
        }

        // Else, return the left key
        else
        {
            return n->left;
        }
    }
}

// Finds the maximum key from tree with root n
NodeKey TST::findMax(Node* n)
{
    // If n is null, then return an empty key
    if (n == nullptr)
    {
        return NodeKey("", 0);
    }

    // Else, traverse right until it is no longer possible
    while (true)
    {
        // If the right subtree exists, then move to the right child
        if (n->rightChild != nullptr)
        {
            n = n->rightChild;
        }

        // Else if right is not empty, then return right
        else if (n->right.key != "" && n->right.count > 0)
        {
            return n->right;
        }

        // Else, return left
        else
        {
            return n->left;
        }
    }
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

// Make a new node with key as left and return it
Node* TST::createNode(std::string key)
{
    Node* n = new Node;
    n->left.key = key;
    n->left.count = 1;
    return n;
}