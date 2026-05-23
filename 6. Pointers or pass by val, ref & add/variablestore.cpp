#include <iostream>
using namespace std;

int main() {
    int var = 10;
    // Declare a pointer 'ptr' that points to an integer
    int* ptr = &var; 

    cout << "Value of var: " << var << endl;       // Outputs 10
    cout << "Address of var: " << &var << endl;    // Outputs memory address (e.g., 0x7ffd...)
    cout << "Value in ptr (address): " << ptr << endl; // Same as &var
    
    return 0;
}
