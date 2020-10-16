// main.cpp

#include "TST.h"

#include <vector>

int main()
{
    TST testTree;

    std::vector<std::string> testVect = {"abcd", "abc", "abd", "ab", "acd", "ac", "ad", "a", "bcd", "bc", "bd", "b", "cd", "c", "d"};   // Inserted not in-order
    
    //std::vector<std::string> testVect = {"a", "ab", "abc", "abcd", "abd", "ac", "acd", "ad", "b", "bc", "bcd", "bd", "c", "cd", "d"}; // Inserted in-order

    for (int i = 0; i < testVect.size(); i++)
    {
        testTree.insert(testVect.at(i) );
    }

    testTree.inOrder();
    testTree.preOrder();
}