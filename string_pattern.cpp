#include <iostream>
#include <string>
using namespace std;

// find first occurrence of pattern in text
int naivePatternMatch(string text, string pattern) {
    if (pattern.empty()) return -1;  // empty pattern

    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break; // mismatch
            }
        }
        if (j == m) {
            return i; // found match
        }
    }
    return -1; // not found
}

// Test cases
void runTests() {
    // 1. Pattern at the beginning
    cout << "Test 1 (beginning): ";
    cout << (naivePatternMatch("hello world", "hello") == 0 ? "PASS" : "FAIL") << endl;

    // 2. Pattern at the end
    cout << "Test 2 (end): ";
    cout << (naivePatternMatch("data structures", "tures") == 9 ? "PASS" : "FAIL") << endl;

    // 3. Pattern not present
    cout << "Test 3 (not present): ";
    cout << (naivePatternMatch("algorithm", "data") == -1 ? "PASS" : "FAIL") << endl;

    // 4. Empty pattern
    cout << "Test 4 (empty pattern): ";
    cout << (naivePatternMatch("test", "") == -1 ? "PASS" : "FAIL") << endl;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int index = naivePatternMatch(text, pattern);
    if (index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found." << endl;

    cout << "\nRunning Test Cases...\n";
    runTests();

    return 0;
}
