/* 1.8 Zero Matrix
 * 
 * Write an element such that if an element in an MxN matrix is 0,
 * its entire row and column are set to zero
 * 
 * Hints
 * 17. If you just cleared th rows and columns as you found 0's, you'd end up clearing 
 *     the whole matrix. Try finding the cells with 0's first before making any changes to the matrix
 * 74. Can you use O(M+N) additional space instead of O(MN). What information 
 *     do you really need from the list of cells that are 0's
 * 102. You probably need some data storage to maintain a list of rows and columns that are zeroed.
 *      Can you use the additional space usage to O(1) by using the matrix itself for storage
 */

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
}


// using the first value in each row or column to represent
// the rest of the row and column. This has space complexity of O(1).
// time complexity of O(MN), which is the fastest it can be for time and
// space combined.
vector<vector<int>> zeroMatrix(vector<vector<int>> mat) {
    // special case to be used later
    bool specialCase = mat[0][0] == 0, firstRow = false, firstCol = false;

    // altering the first value of every row and column if it is a zero value
    for (int m = 0; m < mat.size(); m++) {
        for (int n = 0; n < mat[m].size(); n++) {
            if (mat[m][n] == 0) {
                if (n == 0) firstCol = true;
                if (m == 0) firstRow = true;
                mat[m][0] = 0;
                mat[0][n] = 0;
            }
        }
    }

    // altering each of the rows but the first row
    for (int m = 1; m < mat.size(); m++) {
        int firstValRow = mat[m][0];

        for (int n = 1; n < mat[m].size(); n++) {
            int firstValCol = mat[0][n];
            if (firstValRow == 0) mat[m][n] = 0;
            if (firstValCol == 0) mat[m][n] = 0;
        }
    }

    // special case: if mat[0][0] == 0
    if (firstRow || specialCase) {
        for (int n = 0; n < mat[0].size(); n++) {
            mat[0][n] = 0;
        }
    }
    if (firstCol || specialCase) {
        for (int m = 0; m < mat.size(); m++) {
            mat[m][0] = 0;
        }
    }

    // return matrix
    return mat;
}

int main() {
    vector<vector<int>> mat = vector<vector<int>>(3, vector<int>(4, 1));
    int ind = -5;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            mat[i][j] = ind++;
        }
    }

    printMatrix(mat);
    mat = zeroMatrix(mat);
    cout << "altered" << endl;
    printMatrix(mat);
    
    return 0;
}
