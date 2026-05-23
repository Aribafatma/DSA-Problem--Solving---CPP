#include <iostream>
using namespace std;

int main() {
    // Binary: 5 is 0101, 3 is 0011
    unsigned int a = 5; 
    unsigned int b = 3;

    cout << "a = " << a << ", b = " << b << endl;

    // Bitwise AND: 0101 & 0011 = 0001 (1)
    cout << "a & b: " << (a & b) << endl;

    // Bitwise OR: 0101 | 0011 = 0111 (7)
    cout << "a | b: " << (a | b) << endl;

    // Bitwise XOR: 0101 ^ 0011 = 0110 (6)
    cout << "a ^ b: " << (a ^ b) << endl;

    // Bitwise NOT: Flips all bits
    cout << "~a: " << (~a) << endl;

    // Left Shift: 0101 becomes 1010 (10)
    cout << "a << 1: " << (a << 1) << endl;

    // Right Shift: 0101 becomes 0010 (2)
    cout << "a >> 1: " << (a >> 1) << endl;

    return 0;
}
