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

    void lookup(std::string key); // Prints 'key found, count = x' if found; else, 'key not found'
    void insertPrint(std::string key);    // Prints 'key inserted, new count = x' once key is inserted
    void deletePrint(std::string key);    // Prints 'key deleted, new count = x' if count was previously > 1; else, 'key deleted'
    void rangeSearch(std::string low, std::string high);    // Prints all keys in-order from low to high, double inclusive

    Node* find(std::string key);    // Finds node with key
    Node* insert(std::string key);  // Inserts key to tree
    void deleteKey(std::string key);    // Deletes key from tree
    
    // Test functions
    void inOrder(); // Prints all keys in-order
    void preOrder();    // Prints all keys pre-order
    void postOrder();   // Prints all keys post-order
private:
    Node* root;

    // Function helpers
    void destroyTree(Node* n);  // Destructor helper; deletes memory from tree with root n

    Node* createNode(std::string key); // Make a new node with key

    void rangeSearchRecurs(std::string const& lo, std::string const& hi, Node* n);    // Prints all keys from lo to hi, double inclusive, in-order from root node n
    void inOrderRecurs(Node* n);    // Prints all keys in-order from root node n
    void preOrderRecurs(Node* n);   // Prints all keys pre-order from root node n
    void postOrderRecurs(Node* n);  // Prints all keys post-order from root node n
};

#endif