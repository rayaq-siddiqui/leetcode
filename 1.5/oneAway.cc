/* 1.5 One Away
 * There are three types of edits that can be performed on strings:
 * insert a character
 * remove a character
 * replace a character
 * Given two strings, write a function to check if they are one edit (or zero edits) away
 * 
 * Hints:
 * 23. Start with the easy thing. Can you check each of the edits seperately?
 * 97. What is the relationship between the insert and remove character option. Do these need to be seperate checks?
 * 130. Can you do all three checks in a single pass
 */

#include <iostream>
#include <cstdlib>

using namespace std;

bool oneEditReplace(string s1, string s2) {
    bool foundDifference = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1.at(i) != s2.at(i)) {
            if (foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }
    return true;
}

// assume s1 is smaller
bool oneEditInsert(string s1, string s2) {
    int index1 = 0, index2 = 0;
    while(index2 < s2.length() && index1 < s1.length()) {
        if (s1.at(index1) != s2.at(index2)) {
            if (index1 != index2) {
                return false;
            }
            index2++;
        } 
        else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneAway(string first, string second) {
    if (first.length() == second.length()) return oneEditReplace(first, second);
    else if (first.length() + 1 == second.length()) return oneEditInsert(first, second);
    else if (first.length() - 1 == second.length()) return oneEditInsert(second, first);
    return false;
}

bool oneAwayShort(string first, string second) {
    // length checks
    if (abs((int)(first.length() - second.length())) > 1) {
        return false;
    }

    // get shorter and longer string
    string s1 = first.length() < second.length() ? first : second;
    string s2 = first.length() < second.length() ? second : first;

    int index1 = 0, index2 = 0;
    bool foundDifference = false;
    while(index2 < s2.length() && index1 < s1.length()) {
        if (s1.at(index1) != s2.at(index2)) {
            // ensure that this is the first difference found
            if (foundDifference) return false;
            foundDifference = true;
            
            // one replace, move s1 pointer
            if (s1.length() == s2.length()) index1++;
        } 
        else {
            // if matching, move short pointer
            index1++;
        }
        // always move pointer for longer string
        index2++;
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << oneAway(s1, s2) << " " << oneAwayShort(s1, s2) << endl;
    return 0;
}

