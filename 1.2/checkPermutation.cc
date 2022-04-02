/* Given two strings, write a method to decide if 
 * one is a permutation of the other
 *
 * Hints
 * 1. What is a permutation
 * 84. One solution is O(nlogn) and the other 
 *     requires more space but is O(n)
 * 122. Could a hash table be useful
 * 131. 2 strings that are permutations should 
 *      have the same characters but in different 
 *      orders. Can you make the orders the same
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// can do this with array as well
bool isPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<string, int> count;

    for (int i = 0; i < s1.length(); i++) {
        if (!count[s1.substr(i, 1)]) {
            count[s1.substr(i, 1)] = 1;
        }
        else {
            count[s1.substr(i, 1)] += 1;
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        if (!count[s2.substr(i, 1)] || count[s2.substr(i, 1)] <= 0) {
            return false;
        }
        count[s2.substr(i, 1)] -= 1;
    }
    return true;
}


bool isPermutationSorted(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << isPermutation(s1, s2) << endl;
    cout << isPermutationSorted(s1, s2) << endl;
    return 0;
}
