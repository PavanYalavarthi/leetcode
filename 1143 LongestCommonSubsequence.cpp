/*
Problem credits: https://leetcode.com/problems/longest-common-subsequence/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


Solution:
    dp[i][j] = 1+ dp[i-1][j-1] if text1[i] == text2[j]
                max(dp[i-1][j], dp[i]][j-1]) else
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int>dp(n + 1, 0);
        for(int i = 1; i <= m; i++) {
            for(int j = 1, prev = 0, val; j <= n; j++) {
                val = prev;
                prev = dp[j];
                if (text1[i - 1] == text2[j - 1]) dp[j] = 1 + val;
                else dp[j] = max(dp[j], dp[j-1]);
            }
        }
        return dp[n];
    }
};