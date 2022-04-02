// Implement an algorithm to determine if a 
// string has all unique characters. what 
// if you cannot use additional data structures

/* Hints
 * 44. try a hashtable
 * 117. Could a bit vector be useful
 * 132. Could you solve it in O(nlogn) time
 */

#include <iostream>
#include <unordered_map>

using namespace std;

bool isUnique(string word) {
    if (word.length() > 128) return false;
    unordered_map<string, bool> map;
    bool unique = true;
    for (int i = 0; i < word.length() && unique; i++) {
        string letter = word.substr(i, 1);
        if (!map[letter]) {
            map[letter] = true;
        }
        else {
            unique = false;
        }
    }
    return unique;
}

// textbook implementation
bool isUniqueBit(string word) {
    int checker = 0;
    for (int i = 0; i < word.length(); i++) {
        int val = word.at(i) - 'a';
        if ((checker & (1 << val)) > 0) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

int main() {
    string word;
    cin >> word;
    cout << isUnique(word) << endl;
    cout << isUniqueBit(word) << endl;
}

