/*
Problem credits: https://leetcode.com/problems/longest-palindrome/

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Solution: Calculating freq and adding 1 if there is an odd count
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256] = {0};
        for (char c : s) {
            freq[c]++;
        }
        int ans = 0, odd = 0;
        for(int i=0; i< 256; i++) {
            ans += freq[i] / 2;
            odd = (freq[i] & 1) | odd;
        }
        return ans * 2 + odd;
    }
};