/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * Pushing open brace, and checking it stack top matches with current closing brace
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