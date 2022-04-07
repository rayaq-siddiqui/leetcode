/* 1.6 String Compression
 * Implement a method that performs basic string compression using the counts of repeated characters
 * aabcccccaaa -> a2b1c5a3
 * If the compressed string does not become smaller than the original string, return the original string
 * Assume: only uppercase and lowercase letters
 * 
 * Hints
 * 92. Do the easy thing first, compress the string, then compare the lengths
 * 110. Be careful that you are not repeatedly concatenating strings together (inefficient)
 */

#include <iostream>

using namespace std;

string stringCompression(string s) {
    string curr = s.substr(0, 1);
    int count = 1;
    bool bigger = false;
    string fin = "";

    for (int i = 1; i < s.length(); i++) {
        string c = s.substr(i, 1);
        if (c == curr) {
            count++;
        }
        else {
            fin += curr + to_string(count);
            curr = c;
            count = 1;
        }
        if (count > 1) bigger = true;
    }
    fin += curr + to_string(count);
    return bigger ? fin : s;
}

// the only more efficient way to this would be by using a library like StringBuilder in Java
// stringstream in c++

int main() {
    string s;
    cin >> s;
    cout << stringCompression(s) << endl;
    return 0;
}
