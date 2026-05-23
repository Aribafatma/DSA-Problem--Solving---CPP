#include <iostream>

using namespace std;

int main() {
    int N, M;
    
    // Read the two input integers
    if (cin >> N >> M) {
        // Extract last digits using % 10 and add them
        int lastDigitN = N % 10;
        int lastDigitM = M % 10;
        
        cout << lastDigitN + lastDigitM << endl;
    }
    
    return 0;
}
