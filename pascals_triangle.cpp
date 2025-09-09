#include <iostream>
using namespace std;

// Function to generate Pascal's Triangle up to n rows
void generatePascalsTriangle(int n) {
    if (n <= 0) {
        cout << "No rows to display." << endl;
        return;
    }

    int arr[50][50]; 

    for (int i = 0; i < n; i++) {
        arr[i][0] = arr[i][i] = 1; // first and last element of each row = 1

        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    // Print the triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Test cases
void runTests() {
    cout << "\nTest n=0 → expect 'No rows':" << endl;
    generatePascalsTriangle(0);

    cout << "\nTest n=1 → expect {1}:" << endl;
    generatePascalsTriangle(1);

    cout << "\nTest n=5 → expect row 5 = {1,4,6,4,1}:" << endl;
    generatePascalsTriangle(5);
}

int main() {
    int n;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> n;

    generatePascalsTriangle(n);

    cout << "\nRunning Test Cases...\n";
    runTests();

    return 0;
}
