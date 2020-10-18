// main.cpp

#include "TST.h"

#include <iostream>
#include <vector>

void startTest(std::string name)
{
    std::cout << "----TEST " << name << "----" << std::endl;
}

void runFirstTests(std::vector<std::string> const& testVect, TST & testTree)
{
    std::cout << "insert():" << std::endl;
    for (int i = 0; i < testVect.size(); i++)
    {
        testTree.insertPrint(testVect.at(i) );
    }
    std::cout << std::endl;

    std::cout << "lookup(not in tree):" << std::endl;
    std::vector<std::string> notInTree = {"e", "a", "abzda", "ab", "bb", "aa", "ca", "db"};
    for (auto i : notInTree)
    {
        testTree.lookup(i);
    }
    std::cout << std::endl;
}

void runSecondTests(std::vector<std::string> const& testVect, TST & testTree)
{
    std::cout << "inOrder():" << std::endl;
    testTree.inOrder();
    std::cout << std::endl;

    std::cout << "preOrder():" << std::endl;
    testTree.preOrder();
    std::cout << std::endl;

    std::cout << "deletePrint():" << std::endl;

    for (auto i : testVect)
    {
        testTree.lookup(i);
        testTree.deletePrint(i);
        testTree.lookup(i);
    }
    std::cout << std::endl;

    std::cout << "lookup(nothing should be left):" << std::endl;
    for (auto i : testVect)
    {
        testTree.lookup(i);
    }
    std::cout << std::endl;
}

void testEmpty()
{
    startTest("empty");

    TST testTree;
    testTree.lookup("a");
    testTree.deletePrint("a");
    testTree.rangeSearch("a", "c");
}

void testRoot()
{
    startTest("root, one element");

    TST testTree;
    std::vector<std::string> testVect = {"a", "a"};
    
    runFirstTests(testVect, testTree);

    std::cout << "rangeSearch(b, z): " << std::endl;
    testTree.rangeSearch("b", "z");
    std::cout << std::endl;

    runSecondTests(testVect, testTree);


    startTest("root, two elements");

    TST testTree2;
    std::vector<std::string> testVect2 = {"a", "b", "b"};

    runFirstTests(testVect2, testTree2);

    std::cout << "rangeSearch(b, z): " << std::endl;
    testTree2.rangeSearch("b", "z");
    std::cout << std::endl;

    runSecondTests(testVect2, testTree2);
}

void testLinear()
{
    startTest("Linear");

    TST testTree;

    std::vector<std::string> testVect = {"i", "ippi", "issippi", "ississippi", "mississippi", "pi", "ppi", "sippi", "sissippi", "i", "ississippi", "ississippi", "sippi", "sissippi"};     // in-order and pre-order

    runFirstTests(testVect, testTree);

    std::cout << "rangeSearch(p, z): " << std::endl;
    testTree.rangeSearch("p", "z");
    std::cout << std::endl;

    runSecondTests(testVect, testTree);
}

void testSmall()
{
    startTest("small");

    TST testTree;
    std::vector<std::string> testVect = {"mississippi", "pi", "ppi", "ississippi", "sippi", "ippi", "i", "sissippi", "ississippi", "sippi", "ippi"};   // not in-order

    runFirstTests(testVect, testTree);
    
    std::cout << "rangeSearch(ip, s): " << std::endl;
    testTree.rangeSearch("ip", "s"); 
    std::cout << std::endl;

    runSecondTests(testVect, testTree);
}

void testLarge()
{
    startTest("Large");
    
    TST testTree;

    std::vector<std::string> testVect = {"bd", "bd", "d", "abd", "bc", "d", "d", "c", "bcd", "bcd", "cd", "ad", "ac", "de"};
    //std::vector<std::string> testVect = {"abd", "ac", "ad", "bc", "bcd", "bd", "c", "cd", "d", "de"};  // In-order
    //std::vector<std::string> testVect = {"bd", "d", "abd", "bc", "ac", "ad", "bcd" "c", "cd", "de"};  // Pre-order

    runFirstTests(testVect, testTree);

    std::cout << "rangeSearch(ac, bcd): " << std::endl;
    testTree.rangeSearch("ac", "bcd");
    std::cout << std::endl;

    runSecondTests(testVect, testTree);
}

void testDestructor()
{
    startTest("Destructor");

    TST testTree;
    
    std::vector<std::string> testVect = {"bd", "bd", "d", "abd", "bc", "d", "d", "c", "bcd", "bcd", "cd", "ad", "ac", "de"};

    for (auto i : testVect)
    {
        testTree.insertPrint(i);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./TSTTest testName" << std::endl;
        return -1;
    }

    std::string testName = argv[1];
    if (testName == "empty")
    {
        testEmpty();
    }
    else if (testName == "root")
    {
        testRoot();
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
    else if (testName == "destructor")
    {
        testDestructor();
    }

    return 0;
}