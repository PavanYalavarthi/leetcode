/*
Problem credits: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

SOlution:
    At givemn index add all possible characters and post filling all the chars, add the string top ans
*/

class Solution {
public:
    vector<string>ans;
    void helper(string& digits, string& s, int i, string phone[]) {
        if (i == digits.size()) {
            ans.push_back(s);
            return ;
        }
        for(char c: phone[digits[i] - '0']) {
            s[i] = c;
            helper(digits, s, i+1, phone);
        }
    }
    vector<string> letterCombinations(string digits) {
        string phone[] = {
            "", "", "abc", "def", "ghi", "jkl",  "mno", "pqrs", "tuv", "wxyz"
        };
        int n = digits.size();
        string s(n, '0');
        helper(digits, s, 0, phone);
        return ans;
    }
};