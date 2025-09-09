#include <iostream>
using namespace std;

// find all indices of key
int findIndices(int arr[], int size, int key, int indices[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices[count++] = i;  // store index
        }
    }
    return count; // number of indices found
}

// Helper to print an array
void printArray(int arr[], int size) {
    if (size == 0) {
        cout << -1;
    } else {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Test case runner
void runTestCase(int arr[], int size, int key, int expected[], int expectedSize, string name) {
    int result[100]; // to store indices
    int foundCount = findIndices(arr, size, key, result);

    cout << name << " -> " << endl;
    cout << "Result: ";
    printArray(result, foundCount);

    cout << "Expected: ";
    printArray(expected, expectedSize);

    bool passed = true;
    if (foundCount != expectedSize) {
        passed = false;
    } else {
        for (int i = 0; i < expectedSize; i++) {
            if (result[i] != expected[i]) {
                passed = false;
                break;
            }
        }
    }

    if (passed) {
        cout << "Test Passed\n";
    } else {
        cout << "Test Failed\n";
    }
    cout << "------------------\n";
}

int main() {
    //Multiple occurrences
    int arr1[] = {1, 2, 1, 4, 5};
    int exp1[] = {0, 2};
    runTestCase(arr1, 5, 1, exp1, 2, "Test Case 1 (Multiple occurrences)");

    //Key not present
    int arr2[] = {1, 2, 3, 4, 5};
    int exp2[] = {}; // empty expected
    runTestCase(arr2, 5, 6, exp2, 0, "Test Case 2 (Key not present)");

    //Empty array
    int arr3[] = {};
    int exp3[] = {};
    runTestCase(arr3, 0, 1, exp3, 0, "Test Case 3 (Empty array)");

    return 0;
}
