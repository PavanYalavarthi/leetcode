/*
Problem credits: https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Solution: using stack to get valid paranthesis. Pushing -1 as index where valid paranthesis is missed.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        stk.push(-1);
        int ans = 0;
        for(int i =0; i< s.length(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if(stk.empty()) stk.push(i);
                else ans = max(ans, i - stk.top());
            }
        }
        return ans;
    }
};