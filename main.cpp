// main.cpp

#include "TST.h"

#include <iostream>
#include <vector>

int main()
{
    TST testTree;

    //std::vector<std::string> testVect = {"abcd", "abc", "abd", "ab", "acd", "ac", "ad", "a", "bcd", "bc", "bd", "b", "cd", "c", "d"};   // Inserted not in-order
    
    //std::vector<std::string> testVect = {"a", "ab", "abc", "abcd", "abd", "ac", "acd", "ad", "b", "bc", "bcd", "bd", "c", "cd", "d"}; // Inserted in-order
    
    //std::vector<std::string> testVect = {"i", "ippi", "issippi", "ississippi", "mississippi", "pi", "ppi", "sippi", "sissippi"};    // in-order
    //std::vector<std::string> testVect = {"ippi", "i", "mississippi", "pi", "ppi", "ississippi", "ippi", "sippi", "sissippi"};   // not in-order

    //std::vector<std::string> testVect = {"bd", "d", "abd", "bc", "c", "bcd", "cd", "ad", "de", "ac"};  // Test
    //std::vector<std::string> testVect = {"abd", "ac", "ad", "bc", "bcd", "bd", "c", "cd", "d", "de"};  // In-order
    //std::vector<std::string> testVect = {"bd", "d", "abd", "bc", "ac", "ad", "bcd" "c", "cd", "de"};  // Pre-order

    std::vector<std::string> testVect = {"bd", "bd", "d", "abd", "bc", "d", "d", "c", "bcd", "bcd", "cd", "ad", "ac", "de"};  // Test duplicates
    
    // std::cout << "insert(): " << std::endl;
    for (int i = 0; i < testVect.size(); i++)
    {
        // testTree.insertPrint(testVect.at(i) );
        testTree.insert(testVect.at(i) );
    }
    
    // std::cout << "lookup(): " << std::endl;
    // for (auto i : testVect)
    // {
    //     testTree.lookup(i);
    // }

    std::vector<std::string> notInTree = {"e", "a", "abzda", "ab", "bb", "aa", "ca", "db"};
    // for (auto i : notInTree)
    // {
    //     testTree.lookup(i);
    // }

    // std::cout << "rangeSearch(): " << std::endl;
    // testTree.rangeSearch("ac", "bcd");

    std::cout << "inOrder():" << std::endl;
    testTree.inOrder();

    std::cout << "preOrder():" << std::endl;
    testTree.preOrder();

    // std::cout << "postOrder():" << std::endl;
    // testTree.postOrder();

    std::cout << "deletePrint():" << std::endl;

    for (auto i : notInTree)
    {
        testTree.deletePrint(i);
    }

    for (auto i : testVect)
    {
        testTree.deletePrint(i);
    }
}