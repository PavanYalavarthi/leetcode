/*
problem credits: https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/

You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

Solution:
    The memoment you see a new character start substring to get maximum count
*/
class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>isProcessed(26, false);
        int count = 0;
        for(char c: s) {
            int ascii = c - 'a';
            if (!isProcessed[ascii]) {
                isProcessed[ascii] = true;
                count++;
            }
        }
        return count;
    }
};