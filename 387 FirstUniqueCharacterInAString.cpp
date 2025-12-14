/*
Problem credits: https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Solution:
    Keep freq of chars and scan through first whose freq is 1
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(26, 0);
        for(char c: s) {
            v[c - 'a']++;
        }
        for(int i = 0;i < s.size(); i++) {
            if (v[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};