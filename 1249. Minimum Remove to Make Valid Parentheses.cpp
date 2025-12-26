/*
Problem credits: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

Solution:
    First pick number of closed paranthesis is possible. Baisng on the count, we can insert open braces
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close =0;
        for(char c: s) {
            if (c == '(') {
                open++;
            } else if (c == ')' && open > 0) {
                close++;
                open--;
            }
        }
        string ans;
        open = close;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (open == 0) continue;
                open--;
            } else if (s[i] == ')') {
                if (close <= open) continue;
                close--;
            }
            ans += s[i];
        }
        return ans;
    }
};