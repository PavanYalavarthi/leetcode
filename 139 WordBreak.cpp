/*
Problem credits: https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Solution:
    Use dp[i] => is s[0..i] can be word broken
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(string word : wordDict) {
                if(int size = word.length(); i >= size && dp[i-size] && s.substr(i-size, size) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};