/*
Problem credits: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

SOlution: on open brace keep maximum count.
*/
class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = 0;
        for(char c: s) {
            if(c == '(') 
                ans = max(ans, ++count);
            else if(c == ')')
                count--;
        }
        return ans;
    }
};