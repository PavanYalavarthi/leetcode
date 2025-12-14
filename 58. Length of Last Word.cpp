/*
Problem credits: https://leetcode.com/problems/length-of-last-word/

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Solution: initially skip all spaces, and keep counting till it hit a space
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() -1, ans = 0;
        for(; s[i] == ' ' ; i--);
        for(; i >= 0 && s[i] != ' '; ans++,i--) ;
        return ans;
    }
};