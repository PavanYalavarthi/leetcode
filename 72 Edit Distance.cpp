/*
Problem credits: https://leetcode.com/problems/edit-distance/

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Solution:
    if chars are same, no operation, we can continue for i-1, j-1
    Else, 1+ 
        (i-1, j-1) for replace,
        (i-1, j) for delete
        (i, j-1) for insert
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n, dp);
    }

    int helper(string w1, string w2, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return i + j;
        if(dp[i][j] != -1) return dp[i][j];
        if (w1[i-1] == w2[j-1]) return dp[i][j] = helper(w1, w2, i -1, j-1, dp);
        return dp[i][j] = 1 + min({helper(w1,w2,i, j-1, dp), helper(w1,w2,i -1, j, dp), helper(w1,w2,i -1, j -1, dp)});
    }
};