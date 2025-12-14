/*
problem credits: https://leetcode.com/problems/palindromic-substrings/

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Solution: Every index can be used for even and odd palindrome, so looping for 2n -1 times, with i/2 as right and i/2 + (i&1) as right
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans =0;
        for(int i = 0; i < 2 * n; i++) {
            int l = i/2, r = i/2 + (i & 1);
            while(l>= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--, r++;
            }
        }
        return ans;
    }
};