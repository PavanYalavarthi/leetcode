/*
problem credits: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Solution: 
    Store first and last occrence of char and find unique chars between them, and incremnt ans with the size of it to form 3 length palindrome
*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        int ans = 0;
        for(int i =0; i < s.size(); i++ ) {
            int curr = s[i] - 'a';
            if(first[curr] == -1) {
                first[curr] = i;
            }
            last[curr] = i;
        }
        for(int i = 0; i < 26; i++) {
            if(first[i] == last[i]) continue;
            unordered_set<char> between = unordered_set(s.begin()+first[i]+1, s.begin()+last[i]);
            ans += between.size();
        }
        return ans;
    }
};