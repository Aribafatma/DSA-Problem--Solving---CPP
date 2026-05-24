#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Adding elements
    s.push(10);
    s.push(20);
    s.push(30); // 30 is now at the top

    // Accessing the top element
    std::cout << "Top element: " << s.top() << std::endl; // Outputs 30

    // Removing the top element
    s.pop(); 
    std::cout << "New top after pop: " << s.top() << std::endl; // Outputs 20

    // Checking size
    std::cout << "Stack size: " << s.size() << std::endl;

    return 0;
}
