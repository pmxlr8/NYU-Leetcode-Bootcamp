#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    // Approach: Use first row and first column as markers
    // to achieve O(1) space complexity

    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row has any zeros
    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        firstRowZero = true;
        break;
      }
    }

    // Check if first column has any zeros
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        firstColZero = true;
        break;
      }
    }

    // Use first row and column as markers for the rest of the matrix
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0; // Mark the row
          matrix[0][j] = 0; // Mark the column
        }
      }
    }

    // Set zeros based on markers (except first row and column)
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // Handle first row
    if (firstRowZero) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }

    // Handle first column
    if (firstColZero) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};

// Time Complexity: O(m * n) - We traverse the matrix a constant number of times
// Space Complexity: O(1) - We use the matrix itself for marking, only using two
// boolean variables
