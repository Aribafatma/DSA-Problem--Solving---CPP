#include <iostream>
#include <set>

int main() {
    // Declaration
    std::set<int> mySet = {40, 10, 30};

    // Insertion
    mySet.insert(20);
    mySet.insert(10); // Duplicate; will not be added

    // Traversal (Elements will be 10, 20, 30, 40)
    for (int x : mySet) {
        std::cout << x << " ";
    }

    // Checking existence
    if (mySet.count(30)) {
        std::cout << "\n30 is in the set";
    }

    return 0;
}
