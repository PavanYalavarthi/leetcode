/*
Problem credits: https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Solution: 
    We use first row and first col to store whether its zero.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroinFirstCol = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int row = 0; row < m; row++) {
            if (matrix[row][0] == 0) zeroinFirstCol = true;
            for (int col = 1; col < n; col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n -1  ; col >= 1; col--) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
            if (zeroinFirstCol) {
                matrix[row][0] = 0;
            }
        }
    }
};