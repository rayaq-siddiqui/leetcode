/* 1.7 rotateMatrix
 * given an image represented by a NxN matrix, where each pixel
 * in the image is represented by an integer, write a method to rotate the
 * by 90 degrees. Can you do this in place?
 * 
 * Hints
 * 51. try thinking about it layer by layer. Can you rotate a specific layer?
 * 100. Rotating a specific layer would mean swapping the layer in 4 arrays.
 *      Can you think of how you would do this for 2 arrays and extend to 4 arrays
 */

#include <iostream>
#include <vector>

using namespace std;

/* My attempts - incorrect
vector<vector<int>> editRow(vector<vector<int>> mat, int row, vector<int> edit) {
    for (int i = 0; i < mat[row].size(); i++) {
        mat[row][i] = edit[i];
    }
    return mat;
}

vector<vector<int>> editCol(vector<vector<int>> mat, int row, vector<int> edit) {
    for (int i = 0; i < mat.size(); i++) {
        mat[i][row] = edit[i];
    }
    return mat;
}

vector<vector<int>> rotateMatrix(vector<vector<int>> mat) {
    vector<int> row;
    for (int i = 0; i < mat.size(); i++) {
        row.push_back(mat[0][i]);
    }
    mat = editCol(editRow(editCol(editRow(mat, num3, arr3), num2, arr2), num, arr), mat.size()-1, row);
    return mat;
}
*/

void printMatrix(vector<vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

/* textbook implementation
 * essentially we are going to do this in theory
 * 
 * for i = 0 in n
 *   temp = top[i]
 *   top[i] = left[i]
 *   left[i] = bottom[i]
 *   bottom[i] = right[i]
 *   right[i] = temp
*/

vector<vector<int>> rotate(vector<vector<int>> matrix) {
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) throw 0;
    int n = matrix.size();

    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer, last = n-1-layer;

        // this is doing the switching itself
        for (int i = first; i < last; i++) {
            int offset = i - first;

            // the algorithm essentially, except we are going to be changing it value by value
            int top = matrix[first][i]; // save top
            
            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>> mat = vector<vector<int>>(3, vector<int>(3, 1));
    int ind = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            mat[i][j] = ind++;
        }
    }

    printMatrix(mat);
    mat = rotate(mat);
    printMatrix(mat);
    
    return 0;
}