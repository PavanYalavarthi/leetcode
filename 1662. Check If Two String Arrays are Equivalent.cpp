/*
problem credits: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

Solution:
    self explanatory
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;
        for(string s : word1) s1 += s;
        for(string s: word2) s2 += s;
        return s1 == s2;
    }
};