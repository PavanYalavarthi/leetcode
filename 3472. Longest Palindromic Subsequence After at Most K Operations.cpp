/*
Problem credits: https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

You are given a string s and an integer k.

In one operation, you can replace the character at any position with the next or previous letter in the alphabet (wrapping around so that 'a' is after 'z'). For example, replacing 'a' with the next letter results in 'b', and replacing 'a' with the previous letter results in 'z'. Similarly, replacing 'z' with the next letter results in 'a', and replacing 'z' with the previous letter results in 'y'.

Return the length of the longest palindromic subsequence of s that can be obtained after performing at most k operations.

Solution:
    check circular difference between left and right character, if it is <= k consume it and add 2 to palindromic substring else skip left or right
*/
class Solution {
public:
    int helper(string& s, int i, int j, int k,  vector<vector<vector<int>>>& dp) {
        if (i >= j) {
            return i ==j;
        }
        int &ans = dp[i][j][k];
        if (ans != -1) return ans;
        ans = max(helper(s, i, j-1, k, dp), helper(s, i+1, j, k, dp));
        int diff = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
        if (k >= diff) {
            ans = max(ans, 2 + helper(s, i+1, j-1, k-diff, dp));
        }
        return ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return helper(s, 0, n-1, k, dp);
    }
};