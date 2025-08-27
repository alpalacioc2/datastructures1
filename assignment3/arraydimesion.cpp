#include <iostream>
using namespace std;

int main() {
    const int outerSize = 7;

    // Step 1: Make an array of int pointers (each will point to another array)
    int* arrayOfArrays[outerSize];

    // Step 2: Allocate an inner array for each element
    for (int i = 0; i < outerSize; ++i) {
        arrayOfArrays[i] = new int[3];  // Let's say each inner array has 3 elements

        // Initialize inner array with some values
        for (int j = 0; j < 3; ++j) {
            arrayOfArrays[i][j] = (i + 1) * 10 + j;  // just an example pattern
        }
    }

    // Step 3: Print all inner arrays and their addresses
    for (int i = 0; i < outerSize; ++i) {
        cout << "Inner array at index " << i << " address: " << arrayOfArrays[i] << endl;
        for (int j = 0; j < 3; ++j) {
            cout << "  arrayOfArrays[" << i << "][" << j << "] = "
                 << arrayOfArrays[i][j]
                 << " at address " << &arrayOfArrays[i][j] << endl;
        }
    }

    // Step 4: Clean up memory
    for (int i = 0; i < outerSize; ++i) {
        delete[] arrayOfArrays[i];
    }

    return 0;
}
