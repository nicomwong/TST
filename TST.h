#ifndef TST_H
#define TST_H

#include <string>

struct NodeKey
{
    NodeKey() : key(""), count(0) {}    // Constructor

    std::string key/* = ""*/;
    int count/* = 0*/;
};

struct Node
{
    Node() : leftChild(nullptr), midChild(nullptr), rightChild(nullptr) {}  // Constructor

    NodeKey left;
    NodeKey right;

    Node* leftChild/* = nullptr*/;
    Node* midChild/* = nullptr*/;
    Node* rightChild/* = nullptr*/;
};

class TST
{
public:
    TST();  // Constructor
    ~TST(); // Destructor

    Node* insert(std::string key);  // Inserts key to tree
    void deleteKey(std::string key);    // Deletes key from tree
    void rangeSearch(std::string low, std::string high);    // Prints all keys in-order from low to high, double inclusive

    // Test functions
    void inOrder(); // Prints all keys in-order
    void preOrder();    // Prints all keys pre-order
    void postOrder();   // Prints all keys post-order
private:
    Node* root;

    Node* createNode(std::string key); // Make a new node with key
    
    // Test function helpers
    void inOrderRecurs(Node* n);    // Prints all keys in-order from root node n
    void preOrderRecurs(Node* n);   // Prints all keys pre-order from root node n
    void postOrderRecurs(Node* n);  // Prints all keys post-order from root node n
};

#endif