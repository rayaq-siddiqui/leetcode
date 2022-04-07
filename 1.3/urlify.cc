/* URLify
 * write a method to replace all spaces in a string with %20
 * You may assume that the string has sufficient space at the end to hold
 * the additional characters, and that you are given the true length
 * of the string
 * 
 * ex: "Mr John Smith    ", 13 -> "Mr%20John%20Smith"
 * 
 * Hints
 * 53. It's often easiest to modify a string by going from the end of string to the beginning
 * 118. You might find that you need to know the number of spaces. Can you count them?
 * 
 */

#include <iostream>

using namespace std;

// assumes that s is only the required amount of spaces (no excess)
void urlify(string &s, int len) {
    int padding = s.length() - len;
    for (int i = len-1; i >= 0; i--) {
        char curr = s.at(i);
        if (curr != ' ') {
            s[i+padding] = curr;
        }
        else {
            s[i+padding] = '0';
            s[i+padding-1] = '2';
            s[i+padding-2] = '%';
            // replace the above 3 lines with (c++ syntax)
            // s.replace(i+padding-2, 3, "%20");
            padding -= 2;
        }
    }
}

void urlifySimple(string &s, int len) {
    s = s.substr(0, len);
    for (int i = 0; i < s.length(); i++) {
        bool space = s.at(i) == ' ';
        if (space) s.replace(i, 1, "%20");
    }
}

int main() {
    string s = "Mr John Smith    ", s2 = "Mr John Smith    ";
    int len = 13;

    urlify(s, len);
    urlifySimple(s2, len);

    cout << s << " " << s2 << endl;
    cout << s.length() << " " << s2.length() << endl;
}
