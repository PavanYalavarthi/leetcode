/*
problem credits: https://leetcode.com/problems/largest-odd-number-in-string/description/

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

Solution:
  scan from last the first odd number and set the substring from 0 to index
*/
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        while(n > 0)
          if((num[--n] - '0') & 1) return num.substr(0,n+1);
        return "";
    }
};