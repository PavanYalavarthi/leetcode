/*
problem credits: https://leetcode.com/problems/valid-parenthesis-string/

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

SOlution: Get max and min count of (. At any point if max < 0, return false
*/
class Solution {
public:
        bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }
};