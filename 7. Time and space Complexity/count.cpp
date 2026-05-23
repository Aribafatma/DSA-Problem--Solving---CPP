#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data(10000, 1);
    
    auto start = std::chrono::high_resolution_clock::now();
    
    // Algorithm to measure (e.g., O(n) traversal)
    for(int i : data) { /* do something */ }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::cout << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}
