/*
Problem credits: https://leetcode.com/problems/transpose-matrix/

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.


Solution:
    res[j][i] = matrix[i][j]
*/
class Solution {
    public int[][] transpose(int[][] matrix) {
        int m = matrix.length, n =matrix[0].length;
        int[][] res = new int[n][m];
        for(int i=0;i<m;i++)
            for(int j = 0;j<n;j++)
                res[j][i] = matrix[i][j];
        return res;
    }
};