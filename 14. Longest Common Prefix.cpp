/*
Problem credits: https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Solution: Pick the min and max string and get the common string between them
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto [a,b] = minmax_element(strs.begin(), strs.end());
        int i = 0;
        string s1 = *a, s2 = *b;
        int len = min(s1.length(), s2.length());
        while(i < len && s1[i] == s2[i] ) i++;
        return s1.substr(0,i);
    }
};