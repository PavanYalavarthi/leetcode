/*
Problem credits: https://leetcode.com/problems/pascals-triangle/

Given an integer numRows, return the first numRows of Pascal's triangle.

Solution:
    row[i][j] = row[i-1][j-1] + row[i-1][j]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int  i = 0; i< numRows; i++) {
            vector<int> row(i + 1);
            row[0] = row[i] = 1;
            for(int j = 1; j < i; j++)
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            ans.push_back(row);
        }
        return ans;
    }
};