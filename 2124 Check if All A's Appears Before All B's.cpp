/*
problem credits: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/

Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

Solution:
    Enable flag when b is hit and check if no b hits post enabling teh flag
*/
class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        for(char c: s) {
            if (c == 'b')
                flag = true;
            else if (flag) {
                return false;
            }
        }
        return true;
    }
};