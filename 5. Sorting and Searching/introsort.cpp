#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

int main() {
    std::vector<int> data = {42, 7, 101, 15, 3};

    // Sorts the vector in ascending order (default)
    std::sort(data.begin(), data.end());

    for (int x : data) std::cout << x << " "; 
    return 0;
}
