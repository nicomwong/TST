// main.cpp

#include "TST.h"

#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./project1.out \"Comma-separated commands\"" << std::endl;
        return 1;
    }

    TST tst;

    std::string commandsStr = argv[1];  // Put argv[1] into the commands string
    
    // Remove every space that immediately follows a comma
    for (int i = 0; i < commandsStr.size(); i++)
    {
        if (commandsStr.at(i) == ' ' && i > 0 && commandsStr.at(i - 1) == ',')
        {
            commandsStr.erase(i, 1);
        }
    }

    std::stringstream ss(commandsStr);  // Put the commands string into ss
    std::vector<std::string> commandsVect;    // Vector to store each command; e.g. "insert x", "range_search a to b"

    // Store each comma-space-separated command into the commands vector
    while ( ss.good() )
    {
        std::string command;
        std::getline(ss, command, ',');
        commandsVect.push_back(command);
    }

    for (std::string command : commandsVect)
    {
        std::stringstream ss2(command); // Put command into ss2
        std::vector<std::string> argsVect; // Vector to store each argument in the command; e.g. "insert", "x"; or, "range_search", "a", "to", "b"
        
        // Store each space-separated token into the arguments vector
        while ( ss2.good() )
        {
            std::string arg;
            std::getline(ss2, arg, ' ');
            argsVect.push_back(arg);
        }

        // Run the function
        std::string function = argsVect.at(0);
        if (function == "lookup")
        {
            tst.lookup( argsVect.at(1) );
        }
        else if (function == "insert")
        {
            tst.insertPrint( argsVect.at(1) );
        }
        else if (function == "delete")
        {
            tst.deletePrint( argsVect.at(1) );
        }
        else if (function == "range_search")
        {
            tst.rangeSearch( argsVect.at(1), argsVect.at(3) );
        }
    }

    return 0;
}