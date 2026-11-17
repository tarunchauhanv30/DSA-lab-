#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) return 0;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    int nonZero = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0) nonZero++;
        }
    }

    cout << "Sparse Matrix (row column value):\\n";
    cout << rows << " " << cols << " " << nonZero << "\\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                cout << i << " " << j << " " << matrix[i][j] << "\\n";
            }
        }
    }

    return 0;
}
