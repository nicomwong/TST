// main.cpp

#include "TST.h"

#include <iostream>
#include <vector>

void startTest(std::string name)
{
    std::cout << "----TEST " << name << "----" << std::endl;
}

void testEmpty()
{
    startTest("empty");

    TST testTree;
    testTree.lookup("a");
    testTree.deletePrint("a");
    testTree.rangeSearch("a", "c");
}

void testLinear()
{
    startTest("Linear");

    TST testTree;

    std::vector<std::string> testVect = {"i", "ippi", "issippi", "ississippi", "mississippi", "pi", "ppi", "sippi", "sissippi", "i", "ississippi", "ississippi", "sippi", "sissippi"};     // in-order and pre-order

    std::cout << "insert():" << std::endl;
    for (int i = 0; i < testVect.size(); i++)
    {
        testTree.insertPrint(testVect.at(i) );
    }

    std::cout << "lookup(not in tree):" << std::endl;
    std::vector<std::string> notInTree = {"e", "a", "abzda", "ab", "bb", "aa", "ca", "db"};
    for (auto i : notInTree)
    {
        testTree.lookup(i);
    }

    std::cout << "rangeSearch(p, z): " << std::endl;
    testTree.rangeSearch("p", "z");

    std::cout << "inOrder():" << std::endl;
    testTree.inOrder();

    std::cout << "preOrder():" << std::endl;
    testTree.preOrder();

    std::cout << "deletePrint():" << std::endl;

    for (auto i : notInTree)
    {
        testTree.deletePrint(i);
    }

    for (auto i : testVect)
    {
        testTree.lookup(i);
        testTree.deletePrint(i);
        testTree.lookup(i);
    }

    std::cout << "lookup(nothing should be left):" << std::endl;
    for (auto i : testVect)
    {
        testTree.lookup(i);
    }
}

void testSmall()
{
    std::vector<std::string> testVect = {"ippi", "i", "mississippi", "pi", "ppi", "ississippi", "ippi", "sippi", "sissippi"};   // not in-order
}

void testLarge()
{
    startTest("Large");
    
    TST testTree;

    std::vector<std::string> testVect = {"bd", "bd", "d", "abd", "bc", "d", "d", "c", "bcd", "bcd", "cd", "ad", "ac", "de"};
    //std::vector<std::string> testVect = {"abd", "ac", "ad", "bc", "bcd", "bd", "c", "cd", "d", "de"};  // In-order
    //std::vector<std::string> testVect = {"bd", "d", "abd", "bc", "ac", "ad", "bcd" "c", "cd", "de"};  // Pre-order

    std::cout << "insert():" << std::endl;
    for (int i = 0; i < testVect.size(); i++)
    {
        testTree.insertPrint(testVect.at(i) );
    }

    std::cout << "lookup(not in tree):" << std::endl;
    std::vector<std::string> notInTree = {"e", "a", "abzda", "ab", "bb", "aa", "ca", "db"};
    for (auto i : notInTree)
    {
        testTree.lookup(i);
    }

    std::cout << "rangeSearch(): " << std::endl;
    testTree.rangeSearch("ac", "bcd");

    std::cout << "inOrder():" << std::endl;
    testTree.inOrder();

    std::cout << "preOrder():" << std::endl;
    testTree.preOrder();

    std::cout << "deletePrint():" << std::endl;

    for (auto i : notInTree)
    {
        testTree.deletePrint(i);
    }

    for (auto i : testVect)
    {
        testTree.lookup(i);
        testTree.deletePrint(i);
        testTree.lookup(i);
    }

    std::cout << "lookup(nothing should be left):" << std::endl;
    for (auto i : testVect)
    {
        testTree.lookup(i);
    }
}

void testHuge()
{

}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./TSTTest testName" << std::endl;
        return 0;
    }

    std::string testName = argv[1];
    if (testName == "empty")
    {
        testEmpty();
    }
    else if (testName == "linear")
    {
        testLinear();
    }
    else if (testName == "small")
    {
        testSmall();
    }
    else if (testName == "large")
    {
        testLarge();
    }
    else if (testName == "huge")
    {
        testHuge();
    }

    return 1;
}