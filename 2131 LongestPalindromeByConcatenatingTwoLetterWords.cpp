/*
Problem credits: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Solution: 
    If both chars of string as same we take half of them to left and rest of them to right making each pair a length of 4, so freq / 2 * 4
    if freq is odd for same chars, we keep flag so that those can be placed between to maximize the string

    else 
        we pick smallest of the freq and then multiply with 4

    Final ans is ans + extraPalindrome * 2
*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (string& word : words) {
            mp[word]++;
        }
        int ans = 0, extraPalindrome = 0;
        for(auto &[s, freq]: mp) {
            string w(s);
            reverse(w.begin(), w.end());
            if (s == w) {
                ans += (freq / 2 * 4);
                if (freq % 2) extraPalindrome = 1;
            } else if (s < w && mp.count(w)) {
                ans += min(freq, mp[w]) * 4;
            }
        }
        return ans + extraPalindrome * 2;
    }
};