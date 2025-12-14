/*
Problem credits: https://leetcode.com/problems/valid-parentheses/description/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Solution: Pushing open brace, and checking it stack top matches with current closing brace
*/

/*
 * Time complexity : O(n)
 * Space complexity : O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return false;
        stack<char>stk;
        unordered_map<char,char> mapping = {{'(',')'}, {'{', '}'}, {'[', ']'}};
        for(char c : s) {
            if (mapping.find(c) != mapping.end()) stk.push(c);
            else if (stk.empty() || c != mapping[stk.top()]) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};