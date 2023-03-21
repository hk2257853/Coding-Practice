#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    // Traverse the bits of n and print its binary representation
    cout << "Binary representation of " << n << ": ";
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
    
    return 0;
}