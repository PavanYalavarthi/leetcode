/*
Problem credits: https://leetcode.com/problems/decode-ways/

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

Solution: 
    Self explanatory
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int prev2 = 1, prev1 = 1;
        for(int i = 1; i < s.length(); i++) {
            int single = (s[i] == '0') ? 0 : prev1;
            int dual = isValidDual(s[i-1], s[i]) ? prev2 : 0;
            prev2 = prev1;
            prev1 = single + dual;
            if(prev1 == 0) return 0;
        }
        return prev1;
    }

    bool isValidDual(char s, char t) {
        return (s == '1' or (s == '2' and t < '7'));
    }
};