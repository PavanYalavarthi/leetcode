/*
problem credits: https://leetcode.com/problems/maximal-square/

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Solution: dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for(int i =0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};