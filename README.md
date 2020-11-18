# TST-Project
Ternary search tree whose keys are strings.

Make sure C++11 and Make are installed.

To use, simply clone this repository then type `make` in bash to generate the `project1.out` executable.

Run with `./project1.out "<comma-separated list of queries/commands>"`

The queries supporter are as follows:

1. `lookup x`:              prints whether x is in the tree
2. `insert x`:              inserts x into the tree
3. `delete x`:              deletes x from the tree
4. `range_search a to b`:   prints the keys in the range [a, b] in non-decreasing order

Example: `./project1.out "insert a, insert abc, insert cba, lookup a, lookup b, range_search a to b, delete a, delete abc"`
