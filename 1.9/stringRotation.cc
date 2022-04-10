/* 1.9 stringRotation
 * Assume that you have a method isSubstring which checks if one word is a substring of another
 * Given s1, s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
 * example: "waterbottle" is a rotation of "erbottlewat"
 * 
 * Hints:
 * 34. If a string is a rotation of another, then it's a rotation at a particular point.
 *     i.e. rotation at character 3 for waterbottle is erbottlewat
 * 88. We are essentially asking if there is a way of splitting the fit string into 2 parts, x and y
 *     such that the first string is xy and the second string is yx
 * 104. Think about hint 2. xy + yx = xyyx
 */

#include <iostream>

using namespace std;

// if s2 is a substring of s2
bool isSubstring(string s1, string s2) {
    return s1.find(s2) != std::string::npos;
}

bool stringRotation(string s1, string s2) {
    // s1 = xy, x2 = yx => s1+s2 = xyyx
    string s = s1+s2;
    int ind = 0;
    bool eq = false;
    while (!eq) {
        ind++;
        string first = s.substr(0, ind), end = s.substr(s.length()-ind, ind);
        if (first == end) eq = true;
    }
    string y1 = s1.substr(ind, (s1.length())-ind), y2 = s2.substr(0, (s2.length())-ind);
    return y1 == y2;
}

bool stringRotationSimple(string s1, string s2) {
    // s1 = xy, x2 = yx => s1+s2 = xyyx
    // s1+s1 = xyxy. Note yx is s2
    if (s1.length() != s2.length() || s1.length() <= 0) return false;
    string s1s1 = s1+s1;
    return isSubstring(s1s1, s2);
}

int main() {
    string s1 = "waterbottle", s2 = "erbottlewat";
    cout << stringRotation(s1,s2) << " " << stringRotationSimple(s1,s2) << endl;
    return 0;
}

