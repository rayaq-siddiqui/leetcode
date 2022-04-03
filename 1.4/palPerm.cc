/* 1.4 Palindrome Permutation
 * Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters.
 * The palindrome does not have to be limited to dictionary words.
 * You can ignore casing and non-letter characters
 * 
 * Hints:
 * 106. You do not have to - and should not - generate all permutations
 * 121. What characteristics would a string that is a permutation of a palindrom have
 * 134. Have you tried a hashtable O(n)
 * 136. Can you reduce the speed usage using a bit vector
 */

#include <iostream>
#include <unordered_map>
#include <cctype>

using namespace std;

bool isPalindrome(string s) {
    unordered_map<char, int> map;
    bool odd = false;

    for (char c: s) {
        c = tolower(c);
        if (c >= 97 && c <= 122) {
            if (!map[c]) map[c] = 1;
            else map[c] += 1;
        }
    }
    for (auto& it : map) {
        if (it.second % 2 != 0) {
            if (!odd) odd = true;
            else return false;
        }
    }

    return true;
}

bool isPowerOfTwo(double i) {
    if (i == 1 || i == 0) return true;
    else if (i < 1) return false;
    return isPowerOfTwo(i/2.0);
}

bool isPalindromeBit(string s) {
    int checker = 0;
    for (char c : s) {
        c = tolower(c);
        if (c >= 97 && c <= 122) {
            int val = c - 'a';
            if ((checker & (1 << val)) > 0) {
                checker ^= (1 << val);
            }
            else {
                checker |= (1 << val);
            }
        }
    }
    return isPowerOfTwo(checker);
}

int main() {
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << " " << isPalindromeBit(s) << endl;
    return 0;
}
