#include <iostream>
using namespace std;

int findMode(int arr[], int n) {
    if (n == 0) {
        return -1; // empty array
    }

    int mode = arr[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;

       
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

int main() {
    // Unique mode
    int arr1[] = {1, 2, 2, 3, 4};
    cout << "Mode (unique): " << findMode(arr1, 5) << endl;

    // Multiple modes (any valid one can be returned)
    int arr2[] = {1, 2, 3, 1, 2};
    cout << "Mode (multiple possible): " << findMode(arr2, 5) << endl;

    // Empty array
    int arr3[] = {};
    cout << "Mode (empty): " << findMode(arr3, 0) << endl;

    return 0;
}
