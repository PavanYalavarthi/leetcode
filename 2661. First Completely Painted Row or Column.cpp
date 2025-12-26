/*
problem credits: https://leetcode.com/problems/first-completely-painted-row-or-column/description/

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

Solution:
    Store row and col for each eleemnt and for 1 .. n, increment respective row and col. If row or col equals to #cols or #rows respectively, return i;
*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>>mp;
        for(int i =0; i < rows; i++) 
            for(int j = 0; j < cols; j++)
                mp[mat[i][j]] = {i, j};
        vector<int> rowCount(rows, 0), colCount(cols, 0);
        for(int i =0; i <arr.size(); i++) {
            auto& [row, col] = mp[arr[i]];
            rowCount[row]++;
            colCount[col]++;
            if(rowCount[row] == cols || colCount[col] == rows) {
                return i;
            }
        }
        return -1;
    }
};